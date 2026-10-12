/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x60a7a0; label: FUN_0060a7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

