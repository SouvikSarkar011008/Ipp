"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.deactivate = exports.activate = void 0;
const vscode = require("vscode");
function activate(context) {
    // Register commands for running Ipp code
    const runCommand = vscode.commands.registerCommand('ipp.run', () => {
        var _a, _b;
        const editor = vscode.window.activeTextEditor;
        if (editor) {
            const document = editor.document;
            if (document.languageId === 'ipp') {
                const terminal = vscode.window.createTerminal({
                    name: 'Ipp Runner',
                    cwd: (_b = (_a = vscode.workspace.workspaceFolders) === null || _a === void 0 ? void 0 : _a[0]) === null || _b === void 0 ? void 0 : _b.uri.fsPath
                });
                terminal.sendText(`python main.py run "${document.fileName}"`);
                terminal.show();
            }
        }
    });
    const checkCommand = vscode.commands.registerCommand('ipp.check', () => {
        var _a, _b;
        const editor = vscode.window.activeTextEditor;
        if (editor) {
            const document = editor.document;
            if (document.languageId === 'ipp') {
                const terminal = vscode.window.createTerminal({
                    name: 'Ipp Checker',
                    cwd: (_b = (_a = vscode.workspace.workspaceFolders) === null || _a === void 0 ? void 0 : _a[0]) === null || _b === void 0 ? void 0 : _b.uri.fsPath
                });
                terminal.sendText(`python main.py check "${document.fileName}"`);
                terminal.show();
            }
        }
    });
    context.subscriptions.push(runCommand, checkCommand);
}
exports.activate = activate;
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map