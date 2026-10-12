/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6d0a40; label: FUN_006d0a40
 */

undefined4 FUN_006d0a40(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *local_c;
  int *local_8;
  int local_4;
  
  puVar5 = *(undefined4 **)(in_ECX + 0xc);
  iVar6 = 0;
  local_c = (int *)0x0;
  local_8 = (int *)0x0;
  local_4 = 0;
  for (; puVar2 = DAT_0081fa94, puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
    puVar5[0x1d] = iVar6;
    iVar6 = iVar6 + 1;
  }
joined_r0x006d0a7c:
  if (puVar2 == (undefined4 *)0x0) {
    piVar1 = *(int **)(in_ECX + 0xc);
    while (piVar1 != (int *)0x0) {
      if (*piVar1 == 0) {
        *(int *)(in_ECX + 0x10) = piVar1[1];
      }
      else {
        *(int *)(*piVar1 + 4) = piVar1[1];
      }
      if ((int *)piVar1[1] == (int *)0x0) {
        *(int *)(in_ECX + 0xc) = *piVar1;
      }
      else {
        *(int *)piVar1[1] = *piVar1;
      }
      *piVar1 = 0;
      piVar1[1] = 0;
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + -1;
      FUN_0061ec10(piVar1[2]);
      if ((undefined4 *)piVar1[2] != (undefined4 *)0x0) {
        for (puVar5 = *(undefined4 **)piVar1[2]; puVar5 != (undefined4 *)0x0;
            puVar5 = (undefined4 *)*puVar5) {
          if ((undefined4 *)puVar5[3] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)puVar5[3])(1);
          }
        }
      }
      FUN_00624220(piVar1[2]);
      FUN_006334d0(piVar1,0x78);
      piVar1 = *(int **)(in_ECX + 0xc);
    }
    *(int **)(in_ECX + 0xc) = local_c;
    *(int **)(in_ECX + 0x10) = local_8;
    *(int *)(in_ECX + 0x14) = local_4;
    if (DAT_02973a7c == 0) {
      DAT_02973a48 = param_1;
      puVar5 = (undefined4 *)FUN_006c5c10(*(undefined4 *)(in_ECX + 0xc));
      if (puVar5 != (undefined4 *)0x0) {
        FUN_006bdf50(puVar5);
        iVar6 = FUN_0062a400(puVar5[2],*(undefined4 *)(param_1 + 0x44),
                             *(undefined4 *)(param_1 + 0x40));
        if (iVar6 != 0) {
          return 1;
        }
      }
      puVar2 = *(undefined4 **)(in_ECX + 0xc);
      do {
        do {
          puVar3 = puVar2;
          if (puVar3 == (undefined4 *)0x0) {
            if ((*(uint *)(*(int *)(param_1 + 0x40) + 0x78) & 0x100) != 0) {
              FUN_006cd080();
            }
            DAT_02973a48 = 0;
            return 0;
          }
          puVar2 = (undefined4 *)*puVar3;
        } while (puVar3 == puVar5);
        FUN_006bdf50(puVar3);
        iVar6 = FUN_0062a400(puVar3[2],*(undefined4 *)(param_1 + 0x44),
                             *(undefined4 *)(param_1 + 0x40));
      } while (iVar6 == 0);
      return 1;
    }
    return 0;
  }
  piVar7 = *(int **)(in_ECX + 0xc);
  for (piVar1 = piVar7; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    iVar6 = 0;
    if (0 < piVar1[0x1c]) {
      piVar8 = piVar1 + 5;
      do {
        if (puVar2[3] == *piVar8) {
          piVar1[0x1c] = 0;
          piVar1[4] = puVar2[2];
          piVar1[5] = puVar2[3];
          piVar1[6] = puVar2[4];
          piVar1[0x1c] = piVar1[0x1c] + 1;
          if (*piVar1 == 0) {
            *(int *)(in_ECX + 0x10) = piVar1[1];
          }
          else {
            *(int *)(*piVar1 + 4) = piVar1[1];
          }
          if ((int *)piVar1[1] == (int *)0x0) {
            *(int *)(in_ECX + 0xc) = *piVar1;
          }
          else {
            *(int *)piVar1[1] = *piVar1;
          }
          *piVar1 = 0;
          piVar1[1] = 0;
          *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + -1;
          if (local_c == (int *)0x0) goto LAB_006d0b6b;
          piVar7 = local_c;
          goto LAB_006d0b60;
        }
        iVar6 = iVar6 + 1;
        piVar8 = piVar8 + 3;
      } while (iVar6 < piVar1[0x1c]);
    }
  }
  iVar6 = FUN_006c5b50(local_c,puVar2);
  if (iVar6 == 0) {
    for (; piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
      iVar6 = piVar7[2];
      DAT_0081f9e8 = *(int *)(iVar6 + 0x14);
      if (DAT_0081f9e8 < 1) {
        DAT_0081f9e8 = 0x14;
      }
      DAT_0081f9ec = *(int *)(iVar6 + 0x18);
      if (DAT_0081f9ec < 1) {
        DAT_0081f9ec = 5;
      }
      DAT_0081f9f0 = *(undefined4 *)(iVar6 + 0x1c);
      DAT_0081f9f4 = *(undefined4 *)(iVar6 + 0x20);
    }
    iVar4 = FUN_006ccf00(puVar2 + 2);
    iVar6 = *(int *)(iVar4 + 8);
    *(int *)(iVar6 + 0x14) = DAT_0081f9e8;
    *(int *)(iVar6 + 0x18) = DAT_0081f9ec;
    *(undefined4 *)(iVar6 + 0x1c) = DAT_0081f9f0;
    *(undefined4 *)(iVar6 + 0x20) = DAT_0081f9f4;
    *(undefined4 *)(iVar4 + 0x74) = 0xffffffff;
    FUN_006c20e0(iVar4);
  }
  else if (*(int *)(iVar6 + 0x70) < 8) {
    puVar5 = (undefined4 *)(iVar6 + 0x10 + *(int *)(iVar6 + 0x70) * 0xc);
    *puVar5 = puVar2[2];
    puVar5[1] = puVar2[3];
    puVar5[2] = puVar2[4];
    *(int *)(iVar6 + 0x70) = *(int *)(iVar6 + 0x70) + 1;
  }
  goto LAB_006d0c5b;
  while (piVar7 = (int *)*piVar7, piVar7 != (int *)0x0) {
LAB_006d0b60:
    if (piVar1[0x1d] < piVar7[0x1d]) {
      *piVar1 = (int)piVar7;
      piVar1[1] = piVar7[1];
      if ((undefined4 *)piVar7[1] == (undefined4 *)0x0) {
        local_4 = local_4 + 1;
        piVar7[1] = (int)piVar1;
        local_c = piVar1;
      }
      else {
        local_4 = local_4 + 1;
        *(undefined4 *)piVar7[1] = piVar1;
        piVar7[1] = (int)piVar1;
      }
      goto LAB_006d0c5b;
    }
  }
LAB_006d0b6b:
  *piVar1 = 0;
  piVar1[1] = (int)local_8;
  if (local_8 != (int *)0x0) {
    *local_8 = (int)piVar1;
  }
  if (local_c == (int *)0x0) {
    local_c = piVar1;
  }
  local_4 = local_4 + 1;
  local_8 = piVar1;
LAB_006d0c5b:
  puVar2 = (undefined4 *)*puVar2;
  goto joined_r0x006d0a7c;
}

