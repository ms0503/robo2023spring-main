set-location "$PSScriptRoot"
write-host "コミット前にclang-formatによるlintが行われます。"
if(!(clang-format --version) -and !(test-path "C:\Program Files\LLVM\bin\clang-format.exe")) {
    write-host "clang-formatがインストールされていないか既定の場所に存在しません。"
    write-host "clang-formatをインストールして下さい。"
    write-host "既に既定の場所以外の場所にインストールしている場合、clang-format.exeの存在するディレクトリをPATHをへ追加して下さい。"
    exit 1
}
if(((test-path ".\.git\hooks\pre-commit") -and (((get-acl ".\.git\hooks\pre-commit").Access | where-object {$_.IdentityReference -match "$User" -and $_.AccessControlType -match "Allow"} | foreach-object {$t = $False} {$t = (($_FileSystemRights -band [System.Security.AccessControl.FileSystemRights]::Write) -eq [System.Security.AccessControl.FileSystemRights]::Write) -or $t} {$t}) -eq "False")) -or ((test-path ".\.git\modules\libmecha\hooks\pre-commit") -and (((get-acl ".\.git\modules\libmecha\hooks\pre-commit").Access | where-object {$_.IdentityReference -match "$User" -and $_.AccessControlType -match "Allow"} | foreach-object {$t = $False} {$t = (($_FileSystemRights -band [System.Security.AccessControl.FileSystemRights]::Write) -eq [System.Security.AccessControl.FileSystemRights]::Write) -or $t} {$t}) -eq "False"))) {
    write-host "pre-commitフックへの書き込み権限がありません。"
    write-host "インストールする事が出来ません。"
    exit 2
}
$result = $host.ui.PromptForChoice("", "インストールしますか？", [System.Management.Automation.Host.ChoiceDescription[]]((new-object System.Management.Automation.Host.ChoiceDescription "&y" "インストールする。"), (new-object System.Management.Automation.Host.ChoiceDescription "&n" "インストールを中断する。")), 0)
if($result -eq 1) {
    write-host "中断しました。"
    exit 0
}
if(!(test-path ".\.git\hooks\pre-commit")) {
    write-output "#!/bin/sh" | set-content ".\.git\hooks\pre-commit"
    write-output "exec 1>&2" | add-content ".\.git\hooks\pre-commit"
}
write-output ".\pre-commit-hook.sh" | add-content ".\.git\hooks\pre-commit"
if(!(test-path ".\.git\modules\libmecha\hooks\pre-commit")) {
    write-output "#!/bin/sh" | set-content ".\.git\modules\libmecha\hooks\pre-commit"
    write-output "exec 1>&2" | add-content ".\.git\modules\libmecha\hooks\pre-commit"
}
write-output ".\pre-commit-hook.sh" | add-content ".\.git\modules\libmecha\hooks\pre-commit"
write-host "インストールに成功しました。"
exit 0
