/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x6371d0; label: FUN_006371d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006371d0(int param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined1 local_144 [324];
  
  FUN_005d8400(0,6,"RTL srch");
  if (param_2 == (undefined1 *)0x0) {
    param_2 = local_144;
    FUN_00636010(param_2,1);
  }
  else {
    FUN_00636010(param_2,0);
    if ((*(int *)(param_2 + 0x4c) != 0) &&
       (*(short *)(*(int *)(param_2 + 0x4c) + 0x6a) != *(short *)(param_2 + 0x74))) {
      *(undefined4 *)(param_2 + 0x4c) = 0;
      *(undefined4 *)(param_2 + 0x5c) = 0;
      *(undefined2 *)(param_2 + 0x74) = 0;
    }
  }
  if ((_DAT_02913970 != 0) && (DAT_0080fde4 != 0)) {
    FUN_00636810(0,param_2,param_3,param_5);
  }
  if (param_1 != 0) {
    FUN_00636810(param_1,param_2,param_3,param_5);
  }
  FUN_00636490(param_3,param_4,param_6);
  FUN_00637030();
  FUN_005d8440(0,6);
  return;
}

