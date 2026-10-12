/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x6371d0; label: FUN_006371d0
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

