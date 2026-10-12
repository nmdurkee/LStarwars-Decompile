/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x633000; label: FUN_00633000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00633000(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,
            int param_9)

{
  int iVar1;
  undefined4 local_8;
  undefined4 uStack_4;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    return 0;
  }
  if ((param_2 != (undefined4 *)0x0) || (param_3 != (undefined4 *)0x0)) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x4c))
                      (*(int **)(param_1 + 0x4c),0,&local_8,0,-(uint)(param_9 != 0) & 0x2000);
    if (iVar1 < 0) {
      return 0;
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = uStack_4;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = local_8;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 0;
    }
    if (param_7 != (undefined4 *)0x0) {
      *param_7 = *(undefined4 *)(param_1 + 0x14);
    }
    if (param_8 != (undefined4 *)0x0) {
      *param_8 = *(undefined4 *)(param_1 + 0x18);
    }
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + 8);
  }
  *(undefined4 *)(param_1 + 0x1c) = 1;
  return 1;
}

