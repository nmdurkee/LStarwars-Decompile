/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x73ed28; label: FUN_0073ed28
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0073ed28(int param_1,undefined4 param_2,undefined4 param_3,LPCSTR param_4,int param_5)

{
  undefined4 uVar1;
  HWND hWnd;
  int iVar2;
  char *lpText;
  char *lpCaption;
  UINT uType;
  int local_1248;
  char local_1244 [1024];
  char local_e44 [3000];
  undefined1 local_28c [260];
  char local_188 [256];
  char local_88 [128];
  undefined4 local_8;
  
  local_8 = DAT_00829570;
  FID_conflict__StringCbPrintfA(local_88,0x80,(STRSAFE_LPCSTR)&PTR_LAB_007e7950,param_2);
  if (param_1 != 0) {
    FID_conflict__StringCbPrintfA(local_e44,3000,"%s(%s): ",param_1,local_88);
    OutputDebugStringA(local_e44);
  }
  local_1248 = 0;
  if (param_4 != (LPCSTR)0x0) {
    FUN_00715886(param_4,0x400,&local_1248);
    if (local_1248 != 0) {
      OutputDebugStringA(param_4);
      OutputDebugStringA(" ");
    }
  }
  uVar1 = FUN_007158f6(param_3,param_3);
  FID_conflict__StringCbPrintfA(local_188,0x100,"%s (0x%0.8x)",uVar1);
  FID_conflict__StringCbPrintfA(local_e44,3000,"hr=%s",local_188);
  OutputDebugStringA(local_e44);
  OutputDebugStringA("\n");
  if (param_5 != 0) {
    _StringCopyWorkerA_12(local_28c,0x104,&DAT_007516c0);
    if (param_1 != 0) {
      _StringCopyWorkerA_12(local_28c,0x104,param_1);
    }
    _StringCopyWorkerA_12(local_1244,0x400,&DAT_007516c0);
    if (local_1248 != 0) {
      FID_conflict__StringCbPrintfA(local_1244,0x400,"Calling: %s\n",param_4);
    }
    FID_conflict__StringCbPrintfA
              (local_e44,3000,
               "File: %S\nLine: %s\nError Code: %s\n%sDo you want to debug the application?",
               local_28c,local_88,local_188,local_1244);
    uType = 0x14;
    lpCaption = "Unexpected error encountered";
    lpText = local_e44;
    hWnd = GetForegroundWindow();
    iVar2 = MessageBoxA(hWnd,lpText,lpCaption,uType);
    if (iVar2 == 6) {
      DebugBreak();
    }
  }
  __security_check_cookie(local_8);
  return;
}

