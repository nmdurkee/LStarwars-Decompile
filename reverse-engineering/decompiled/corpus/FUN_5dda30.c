/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5dda30; label: FUN_005dda30
 */

undefined4 FUN_005dda30(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_4 != 0) {
    FUN_00607ec0(0xd,7,param_2,param_3);
    if (0 < param_4) {
      puVar4 = (undefined4 *)(param_1 + 0x20);
      do {
        FUN_005c1f70();
        uVar1 = *puVar4;
        puVar3 = (undefined4 *)*DAT_02854d10;
        puVar3[4] = puVar4[-1];
        puVar3[5] = uVar1;
        uVar1 = puVar4[-7];
        uVar2 = puVar4[-6];
        *puVar3 = puVar4[-8];
        puVar3[1] = uVar1;
        *(undefined4 *)(*DAT_02854d10 + 8) = uVar2;
        *DAT_02854d10 = *DAT_02854d10 + 0x18;
        DAT_02854d14 = DAT_02854d14 + 1;
        param_4 = param_4 + -1;
        puVar4 = puVar4 + 9;
      } while (param_4 != 0);
    }
    FUN_006009c0();
  }
  return 1;
}

