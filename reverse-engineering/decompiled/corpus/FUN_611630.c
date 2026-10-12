/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x611630; label: FUN_00611630
 */

void FUN_00611630(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  uint local_10;
  int local_8;
  
  uVar6 = FUN_00617a00();
  if (*(uint *)(in_ECX + 0x17bc) < uVar6) {
    uVar8 = 0;
    if (*(int *)(in_ECX + 0xc) < 3) {
      local_10 = *(uint *)(in_ECX + 0x17c0);
    }
    else {
      local_10 = *(uint *)(in_ECX + 0x17c4);
    }
    piVar2 = *(int **)(in_ECX + 4);
    while ((piVar2 != (int *)0x0 && (uVar8 < local_10 / 0x1e))) {
      if ((uVar6 < (uint)piVar2[7]) ||
         ((uVar6 < (uint)piVar2[6] && ((uint)piVar2[4] < *(uint *)(in_ECX + 0x38))))) {
        piVar2 = (int *)*piVar2;
      }
      else {
        piVar1 = (int *)*piVar2;
        *(int *)(in_ECX + 0x17d4) = *(int *)(in_ECX + 0x17d4) + piVar2[4];
        *(int *)(in_ECX + 0x17dc) = *(int *)(in_ECX + 0x17dc) + 1;
        iVar7 = FUN_00611290(piVar2);
        uVar8 = uVar8 + iVar7;
        if (*piVar2 == 0) {
          *(int *)(in_ECX + 8) = piVar2[1];
        }
        else {
          *(int *)(*piVar2 + 4) = piVar2[1];
        }
        if ((int *)piVar2[1] == (int *)0x0) {
          *(int *)(in_ECX + 4) = *piVar2;
        }
        else {
          *(int *)piVar2[1] = *piVar2;
        }
        *piVar2 = 0;
        piVar2[1] = 0;
        *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -1;
        FUN_006334d0(piVar2[3],3000);
        FUN_006334d0(piVar2,0x24);
        piVar2 = piVar1;
      }
    }
    fVar4 = (float)(int)uVar8;
    if ((int)uVar8 < 0) {
      fVar4 = fVar4 + 4.2949673e+09;
    }
    fVar5 = (float)(int)local_10;
    if ((int)local_10 < 0) {
      fVar5 = fVar5 + 4.2949673e+09;
    }
    local_8 = (int)(longlong)ROUND(fVar4 / (fVar5 / 1000.0));
    *(uint *)(in_ECX + 0x17bc) = local_8 + uVar6;
  }
  puVar3 = *(undefined4 **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
    if (((uint)puVar3[7] <= (uint)puVar3[6]) || (uVar6 <= (uint)puVar3[6])) {
      *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + puVar3[4];
    }
  }
  (*(code *)**(undefined4 **)(in_ECX + 0x17cc))();
  (*(code *)**(undefined4 **)(in_ECX + 0x19ec))();
  fVar4 = (float)*(int *)(in_ECX + 0x17d4);
  if (*(int *)(in_ECX + 0x17d4) < 0) {
    fVar4 = fVar4 + 4.2949673e+09;
  }
  if (fVar4 <= 0.0) {
    *(undefined4 *)(in_ECX + 0x1c1c) = 0;
  }
  else {
    fVar5 = (float)*(int *)(in_ECX + 0x19f4);
    if (*(int *)(in_ECX + 0x19f4) < 0) {
      fVar5 = fVar5 + 4.2949673e+09;
    }
    *(float *)(in_ECX + 0x1c1c) = fVar5 / fVar4;
  }
  iVar7 = *(int *)(in_ECX + 0x19fc);
  if (iVar7 == 0) {
    *(undefined4 *)(in_ECX + 0x1c20) = 0;
    *(undefined4 *)(in_ECX + 0x1c18) = *(undefined4 *)(in_ECX + 0xc);
    return;
  }
  fVar4 = (float)*(int *)(in_ECX + 0x19f4);
  if (*(int *)(in_ECX + 0x19f4) < 0) {
    fVar4 = fVar4 + 4.2949673e+09;
  }
  fVar5 = (float)iVar7;
  if (iVar7 < 0) {
    fVar5 = fVar5 + 4.2949673e+09;
  }
  *(undefined4 *)(in_ECX + 0x1c18) = *(undefined4 *)(in_ECX + 0xc);
  *(float *)(in_ECX + 0x1c20) = fVar4 / fVar5;
  return;
}

