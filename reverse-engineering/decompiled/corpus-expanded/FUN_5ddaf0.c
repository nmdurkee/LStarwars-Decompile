/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5ddaf0; label: FUN_005ddaf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005ddaf0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_2 != 0) {
    FUN_00607ec0(0xc,7,param_4,param_3);
    if (0 < param_2) {
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
        param_2 = param_2 + -1;
        puVar4 = puVar4 + 9;
      } while (param_2 != 0);
    }
    FUN_006009c0();
  }
  return 1;
}

