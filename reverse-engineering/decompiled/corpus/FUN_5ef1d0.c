/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ef1d0; label: FUN_005ef1d0
 */

void FUN_005ef1d0(uint *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  uint in_ECX;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  bool bVar11;
  char *pcVar12;
  undefined4 *local_414;
  undefined4 local_410;
  uint *local_40c;
  undefined1 local_408 [1028];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_414;
  local_40c = param_1;
  local_414 = param_2;
  if (in_ECX == 0) {
    FUN_004f7cf0(local_408,param_3,0x400);
    iVar2 = FUN_004fa5f0(local_408);
    if (iVar2 == 0) {
      FUN_005c12f0(param_3);
      goto LAB_005ef472;
    }
    iVar3 = FUN_004f6b40(iVar2);
    *param_1 = *param_1 + 0x1f & 0xffffffe0;
    iVar4 = FUN_00601e20(param_1,*local_414,iVar2);
    in_ECX = *param_1 + 0x1f & 0xffffffe0;
    *param_1 = in_ECX + (iVar3 - iVar4);
    FUN_004fb550(iVar2,in_ECX,iVar3 - iVar4);
    FUN_004f99e0(iVar2);
  }
  iVar2 = *(int *)(in_ECX + 8);
  piVar5 = (int *)FUN_004f4f40(in_ECX + 0x18);
  piVar5 = (int *)*piVar5;
  if (piVar5[0x5a] < 1) {
    if ((iVar2 < 0) || (bVar11 = iVar2 + -2 < 0, 2 < iVar2)) {
      pcVar12 = 
      "Your Scene version is %d, whereas the Engine only accepts Scene versions from %d to %d";
      goto LAB_005ef2c2;
    }
  }
  else if ((iVar2 < 0) || (bVar11 = iVar2 + -2 < 0, 2 < iVar2)) {
    pcVar12 = 
    "Your Character version is %d, whereas the Engine only accepts Character versions from %d to %d"
    ;
LAB_005ef2c2:
    FUN_004feaa0(pcVar12,iVar2,0,2);
    bVar11 = iVar2 + -2 < 0;
  }
  if (SBORROW4(iVar2,2) != bVar11) {
    piVar5[0x7d] = 1;
  }
  FUN_00602370(piVar5,param_1,local_414);
  iVar2 = 0;
  if (0 < piVar5[1]) {
    do {
      iVar3 = *(int *)(piVar5[2] + iVar2 * 4);
      if (*(int *)(iVar3 + 0x18) < 0) {
        *(undefined4 *)(*piVar5 + iVar2 * 4) = 0xabcdabcd;
      }
      else {
        uVar7 = FUN_005e5210(iVar3);
        *(undefined4 *)(*piVar5 + iVar2 * 4) = uVar7;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < piVar5[1]);
  }
  FUN_005eedf0(piVar5);
  uVar9 = 0;
  if (0 < piVar5[0x18]) {
    iVar2 = piVar5[0x18];
    piVar6 = (int *)(piVar5[0x19] + 8);
    do {
      uVar8 = (int)(short)piVar6[1] + *piVar6;
      if (uVar9 < uVar8) {
        uVar9 = uVar8;
      }
      piVar6 = piVar6 + 8;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  uVar8 = 0;
  if (uVar9 != 0) {
    do {
      iVar2 = uVar8 * 2;
      iVar3 = uVar8 * 2;
      uVar8 = uVar8 + 1;
      *(undefined2 *)(piVar5[0x1a] + iVar3) =
           *(undefined2 *)(*piVar5 + (uint)*(ushort *)(piVar5[0x1a] + iVar2) * 4);
    } while (uVar8 < uVar9);
  }
  local_414 = (undefined4 *)0x0;
  if (0 < piVar5[0x18]) {
    iVar2 = 0;
    do {
      puVar1 = DAT_009738d4;
      iVar3 = *(int *)(piVar5[0x19] + 8 + iVar2);
      puVar10 = (undefined4 *)(piVar5[0x19] + iVar2);
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = piVar5[0x1a] + iVar3 * 2;
      *(undefined1 *)((int)puVar10 + 0xe) = 0;
      local_410 = puVar10[7];
      puVar10[4] = *(undefined4 *)(piVar5[3] + puVar10[4] * 4);
      while ((puVar1 != (undefined4 *)0x0 &&
             (iVar3 = FUN_004f8b10(local_410,puVar1 + 2), iVar3 != 0))) {
        puVar1 = (undefined4 *)*puVar1;
      }
      uVar7 = FUN_005d1c20(local_40c,puVar10[4],puVar10[2],puVar1);
      puVar10[5] = uVar7;
      local_414 = (undefined4 *)((int)local_414 + 1);
      iVar2 = iVar2 + 0x20;
    } while ((int)local_414 < piVar5[0x18]);
  }
  iVar2 = 0;
  if (piVar5[0x18] != 1 && -1 < piVar5[0x18] + -1) {
    iVar3 = 0;
    do {
      *(int *)(piVar5[0x19] + iVar3) = (int)((int *)(piVar5[0x19] + iVar3) + 8);
      *(int *)(piVar5[0x19] + iVar3 + 0x24) = piVar5[0x19] + iVar3;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x20;
    } while (iVar2 < piVar5[0x18] + -1);
  }
  FUN_005d3380(piVar5[0x19]);
  if (piVar5[0x44] != 0) {
    FUN_005ded80(piVar5[0x44]);
  }
  FUN_00602550(piVar5);
  piVar5[0x10] = 0;
  piVar5[0x11] = 0;
LAB_005ef472:
  __security_check_cookie(local_4 ^ (uint)&local_414);
  return;
}

