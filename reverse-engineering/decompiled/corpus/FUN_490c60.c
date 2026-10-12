/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x490c60; label: FUN_00490c60
 */

void FUN_00490c60(int param_1,undefined4 param_2,undefined4 *param_3)

{
  float fVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    param_3[1] = 0xffffffff;
    param_3[2] = 0xffffffff;
    if (((param_1 != 0) && (*(int *)(param_1 + 0x5068) != 0)) &&
       (iVar5 = 0, 0 < *(int *)(param_1 + 0x506c))) {
      pbVar3 = (byte *)(*(int *)(param_1 + 0x5068) + 0x94);
      do {
        if (0x1f < iVar5) {
          return;
        }
        iVar2 = (int)((iVar5 >> 0x1f & 0x1fU) + iVar5) >> 5;
        uVar4 = 1 << ((byte)iVar5 & 0x1f);
        if (((*pbVar3 & 2) != 0) &&
           (fVar1 = *(float *)(pbVar3 + -0x1c), !NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0))) {
          param_3[iVar2] = param_3[iVar2] | uVar4;
        }
        if ((*pbVar3 & 0x10) == 0) {
          param_3[iVar2 + 2] = param_3[iVar2 + 2] & ~uVar4;
        }
        if ((*pbVar3 & 0x80) == 0) {
          param_3[iVar2 + 1] = param_3[iVar2 + 1] & ~uVar4;
        }
        iVar5 = iVar5 + 1;
        pbVar3 = pbVar3 + 0xa0;
      } while (iVar5 < *(int *)(param_1 + 0x506c));
    }
  }
  return;
}

