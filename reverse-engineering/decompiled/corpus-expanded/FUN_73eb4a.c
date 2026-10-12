/* Ghidra pseudocode, not original source.
 * ev_d0ee5b940732101f19a6f5ed1cc5d22784960ef3dbbb4fefd6b0cd8a13c6d459
 * Entry: 0x73eb4a; label: FUN_0073eb4a
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0073eb4a(int param_1,undefined4 param_2,undefined4 param_3,LPCWSTR param_4,int param_5)

{
  undefined4 uVar1;
  HWND hWnd;
  int iVar2;
  wchar_t *lpText;
  wchar_t *lpCaption;
  UINT uType;
  int local_2384;
  LPCWSTR local_2380;
  wchar_t local_237c [1024];
  wchar_t local_1b7c [3000];
  wchar_t local_40c [256];
  wchar_t local_20c [128];
  undefined1 local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_00829570;
  local_2380 = param_4;
  _StringCchPrintfW(local_20c,0x80,L"%ld",param_2);
  if (param_1 != 0) {
    _StringCchPrintfW(local_1b7c,3000,L"%S(%s): ",param_1,local_20c);
    OutputDebugStringW(local_1b7c);
  }
  local_2384 = 0;
  if (local_2380 != (LPCWSTR)0x0) {
    FUN_007158bd(local_2380,0x400,&local_2384);
    if (local_2384 != 0) {
      OutputDebugStringW(local_2380);
      OutputDebugStringW(L" ");
    }
  }
  uVar1 = FUN_007275a4(param_3,param_3);
  _StringCchPrintfW(local_40c,0x100,L"%s (0x%0.8x)",uVar1);
  _StringCchPrintfW(local_1b7c,3000,L"hr=%s",local_40c);
  OutputDebugStringW(local_1b7c);
  OutputDebugStringW(L"\n");
  if (param_5 != 0) {
    _StringCopyWorkerA_12(local_10c,0x104,&DAT_007516c0);
    if (param_1 != 0) {
      _StringCopyWorkerA_12(local_10c,0x104,param_1);
    }
    _StringCopyWorkerW_12(local_237c,0x400,&DAT_007e7860);
    if (local_2384 != 0) {
      _StringCchPrintfW(local_237c,0x400,L"Calling: %s\n",local_2380);
    }
    _StringCchPrintfW(local_1b7c,3000,
                      L"File: %S\nLine: %s\nError Code: %s\n%sDo you want to debug the application?"
                      ,local_10c,local_20c,local_40c,local_237c);
    uType = 0x14;
    lpCaption = L"Unexpected error encountered";
    lpText = local_1b7c;
    hWnd = GetForegroundWindow();
    iVar2 = MessageBoxW(hWnd,lpText,lpCaption,uType);
    if (iVar2 == 6) {
      DebugBreak();
    }
  }
  __security_check_cookie(local_8);
  return;
}

