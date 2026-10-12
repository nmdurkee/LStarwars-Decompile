/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bccc0; label: FUN_004bccc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bccc0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  if ((param_1 != 0) || (param_2 != 0)) {
    if (param_3 == 0) {
      iVar4 = 0;
      piVar5 = &DAT_0087b9d8;
      do {
        if (param_2 != 0) {
          if ((*piVar5 != 0) && (iVar3 = FUN_004f8b10(*piVar5 + 0xf2,param_2), iVar3 == 0)) {
            FUN_005687f0(*piVar5);
            *(uint *)(*piVar5 + 0x94) = *(uint *)(*piVar5 + 0x94) | 0x10000;
            goto LAB_004bce0c;
          }
          if (((param_1 != 0) && (iVar3 = FUN_005cfa50(piVar5 + 1), iVar3 != 0)) &&
             (iVar3 = FUN_004f8b10(iVar3,param_1), iVar3 == 0)) {
            piVar1 = piVar5 + 1;
            puVar6 = (undefined4 *)FUN_005cfa20(piVar1);
            puVar2 = (undefined4 *)FUN_005d0370(piVar1);
            for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar2 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar2 = puVar2 + 1;
            }
            FUN_005ea660(piVar1);
LAB_004bce0c:
            *piVar5 = 0;
            piVar5[1] = 0;
            piVar5[2] = 0;
            piVar5[3] = 0;
            piVar5[4] = 0;
            return;
          }
        }
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 5;
        if (7 < iVar4) {
          return;
        }
      } while( true );
    }
    iVar4 = 0;
    puVar6 = &DAT_0087b9d8;
    while (0.0 < (float)puVar6[4]) {
      iVar4 = iVar4 + 1;
      puVar6 = puVar6 + 5;
      if (7 < iVar4) {
        return;
      }
    }
    if (param_2 == 0) {
      if ((param_1 != 0) &&
         (iVar4 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),puVar6 + 1,param_1,1),
         iVar4 != 0)) goto LAB_004bcd62;
    }
    else {
      puVar2 = (undefined4 *)
               FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802f54,param_2);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar6 = *puVar2;
LAB_004bcd62:
        DAT_0087b9d0 = 1;
        puVar6[4] = _DAT_007fc4c4;
        return;
      }
    }
  }
  return;
}

