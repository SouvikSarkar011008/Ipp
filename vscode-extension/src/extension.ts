import * as vscode from 'vscode';

export function activate(context: vscode.ExtensionContext) {
    // Register commands for running Ipp code
    const runCommand = vscode.commands.registerCommand('ipp.run', () => {
        const editor = vscode.window.activeTextEditor;
        if (editor) {
            const document = editor.document;
            if (document.languageId === 'ipp') {
                const terminal = vscode.window.createTerminal({
                    name: 'Ipp Runner',
                    cwd: vscode.workspace.workspaceFolders?.[0]?.uri.fsPath
                });
                terminal.sendText(`python main.py run "${document.fileName}"`);
                terminal.show();
            }
        }
    });

    const checkCommand = vscode.commands.registerCommand('ipp.check', () => {
        const editor = vscode.window.activeTextEditor;
        if (editor) {
            const document = editor.document;
            if (document.languageId === 'ipp') {
                const terminal = vscode.window.createTerminal({
                    name: 'Ipp Checker',
                    cwd: vscode.workspace.workspaceFolders?.[0]?.uri.fsPath
                });
                terminal.sendText(`python main.py check "${document.fileName}"`);
                terminal.show();
            }
        }
    });

    context.subscriptions.push(runCommand, checkCommand);
}

export function deactivate() {}
