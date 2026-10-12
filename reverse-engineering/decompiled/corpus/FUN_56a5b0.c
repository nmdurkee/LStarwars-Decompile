/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x56a5b0; label: FUN_0056a5b0
 */

int FUN_0056a5b0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int local_14;
  
  bVar4 = false;
  bVar5 = false;
  bVar6 = false;
  local_14 = 0;
  if ((param_2 == 0) || ((*(byte *)(param_2 + 0x1fc) & 0x80) == 0)) {
    return 0;
  }
  if (((*(uint *)(*(int *)(param_2 + 0x54) + 4) & 0x2000) == 0) && (*(int *)(param_2 + 0xcd0) == 0))
  {
    bVar5 = true;
  }
  else {
    bVar4 = true;
  }
  iVar9 = 0;
  iVar10 = *(int *)(param_1 + 0x50c8);
  if (0 < *(int *)(param_1 + 0x50c0)) {
    do {
      uVar8 = *(uint *)(iVar10 + 0x94);
      if (((((((uVar8 & 1) == 0) && ((uVar8 & 0x800000) != 0)) && ((uVar8 & 0x4000) != 0)) &&
           ((!bVar4 || ((*(uint *)(iVar10 + 0x98) & 0x200) != 0)))) &&
          ((!bVar5 || ((*(byte *)(iVar10 + 0x98) & 8) != 0)))) && ((uVar8 & 0x2040000) == 0)) {
        fVar1 = *(float *)(param_2 + 0x80) - *(float *)(iVar10 + 0x4c);
        fVar2 = *(float *)(param_2 + 0x84) - *(float *)(iVar10 + 0x50);
        fVar3 = *(float *)(param_2 + 0x88) - *(float *)(iVar10 + 0x54);
        if ((*(float *)(iVar10 + 0xac) == 0.0) ||
           (fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2 <
            *(float *)(iVar10 + 0xac) * *(float *)(iVar10 + 0xac))) {
          if (bVar4) {
            uVar11 = 5;
            uVar8 = uVar8 | 0x10;
          }
          else {
            uVar11 = 4;
            uVar8 = uVar8 | 0x20;
          }
          *(uint *)(iVar10 + 0x94) = uVar8;
          iVar7 = FUN_005d0420(*(int *)(iVar10 + 0xa4) + 0x30);
          if (*(float *)(iVar10 + 0xb8) <= 0.0) {
            if ((iVar7 != 0) && ((*(uint *)(iVar10 + 0x94) & 0x80000) == 0)) {
              *(undefined4 *)(iVar10 + 0xbc) = 0;
              *(uint *)(iVar10 + 0x94) = *(uint *)(iVar10 + 0x94) | 0x2080000;
              goto LAB_0056a73c;
            }
            bVar6 = true;
          }
          else {
            *(uint *)(iVar10 + 0x94) = *(uint *)(iVar10 + 0x94) | 0x40000;
            *(undefined4 *)(iVar10 + 0xb4) = *(undefined4 *)(iVar10 + 0xb8);
LAB_0056a73c:
            if (!bVar6) goto LAB_0056a75d;
          }
          FUN_00567800(iVar10,1,uVar11,1,param_2,1);
          local_14 = local_14 + 1;
        }
      }
LAB_0056a75d:
      iVar9 = iVar9 + 1;
      iVar10 = iVar10 + 0x114;
    } while (iVar9 < *(int *)(param_1 + 0x50c0));
  }
  return local_14;
}

