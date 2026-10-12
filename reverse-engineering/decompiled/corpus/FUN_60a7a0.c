/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x60a7a0; label: FUN_0060a7a0
 */

void FUN_0060a7a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7)

{
  char cVar1;
  undefined1 local_1c [24];
  short local_4;
  
  if (param_1 == 0) {
    if ((param_6 == DAT_00973900) && (param_7 == DAT_00973904)) {
      cVar1 = '\0';
    }
    else {
      cVar1 = '\x01';
    }
    FUN_006069a0();
    FUN_005fb870(param_2,param_3,0);
    FUN_006e2320(local_1c,cVar1 + '\x01',0);
    FUN_005fb810();
    (&DAT_00986a88)[local_4] = 0;
    return;
  }
  FUN_005f7490();
  return;
}

