/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x513540; label: FUN_00513540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00513540(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if ((DAT_0092221c != 0) && (iVar1 = FUN_004f7fb0(param_1), iVar1 != 0)) {
    if ((DAT_00922214 == (int *)0x0) ||
       ((DAT_00922218 == (uint *)0x0 || (*DAT_00922218 <= *DAT_00922214 + 0x24U)))) {
      uVar5 = FUN_00512850();
    }
    else {
      uVar4 = *DAT_00922214 + 0xf;
      puVar2 = (undefined4 *)(uVar4 & 0xfffffff0);
      uVar5 = CONCAT44(DAT_00922218,uVar4) & 0xfffffffffffffff0;
      *DAT_00922214 = (uVar4 & 0xfffffff0) + 0x24;
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2[8] = 0;
    }
    puVar2 = (undefined4 *)uVar5;
    DAT_0092222c = puVar2 + 7;
    DAT_00922220 = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2[8] = 0;
      uVar3 = FUN_00513100(*(undefined4 *)(param_1 + 0x510),(int)(uVar5 >> 0x20));
      DAT_00922220[6] = uVar3;
      iVar1 = FUN_004f8b10(uVar3,&DAT_00753270);
      if (iVar1 == 0) {
        FUN_004f1340(DAT_0092221c + 0x10,DAT_00922220);
      }
      else {
        FUN_004f1310(DAT_0092221c + 0x10,DAT_00922220);
      }
      FUN_004f10e0(param_1,&PTR_s_CONDITIONS_008016f4);
      iVar1 = FUN_004fc5b0(param_1);
      while (iVar1 != 0) {
        FUN_004f7fb0(param_1);
        DAT_00922230 = DAT_00922220 + 2;
        DAT_00922234 = DAT_00922220 + 4;
        FUN_004fa020(param_1);
        iVar1 = FUN_004fc5b0(param_1);
      }
      FUN_004f11e0(param_1);
      DAT_0092222c = (undefined4 *)0x0;
      DAT_00922220 = (undefined4 *)0x0;
      DAT_00922230 = (undefined4 *)0x0;
      DAT_00922234 = (undefined4 *)0x0;
    }
  }
  return;
}

