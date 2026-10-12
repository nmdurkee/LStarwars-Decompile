/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x555150; label: FUN_00555150
 */

int FUN_00555150(uint param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  float *pfVar10;
  
  iVar4 = param_1;
  if (param_1 == 0) {
    return 0;
  }
  bVar3 = *(byte *)(param_1 + 0x8b);
  uVar9 = *(uint *)(param_1 + 0x84) & 6;
  if (bVar3 != 0) {
    fVar1 = *(float *)(param_1 + 0x98);
    fVar2 = *(float *)(param_1 + 0x60);
    iVar5 = (int)(0x10000 / (ulonglong)(longlong)(int)(uint)bVar3);
    uVar7 = (uint)(ushort)(*(short *)(param_1 + 0x8c) + *(short *)(param_1 + 0x82) +
                           *(short *)(param_1 + 0x7c) + 0x8000);
    if ((uVar9 == 0) || (param_1 = uVar7 - 0x4000, uVar9 == 6)) {
      param_1 = uVar7 + 0x4000;
    }
    param_1 = param_1 & 0xffff;
    iVar8 = 0;
    if (bVar3 != 0) {
      puVar6 = (undefined4 *)(param_3 + 8);
      pfVar10 = param_2;
      do {
        if (param_3 != 0) {
          puVar6[-2] = (&DAT_029899a0)[param_1 >> 1 & 0x7fff];
          puVar6[-1] = 0;
          *puVar6 = (&DAT_029899a0)[(int)((param_1 & 0xffff) + 0x4000) >> 1 & 0x7fff];
        }
        if (param_2 != (float *)0x0) {
          *pfVar10 = (float)(&DAT_029899a0)[(uVar7 & 0xffff) >> 1] * *(float *)(iVar4 + 0x94) +
                     *(float *)(iVar4 + 0x5c);
          pfVar10[1] = fVar1 + fVar2;
          *(float *)(((int)param_2 - param_3) + (int)puVar6) =
               (float)(&DAT_029899a0)[(int)((uVar7 & 0xffff) + 0x4000) >> 1 & 0x7fff] *
               *(float *)(iVar4 + 0x94) + *(float *)(iVar4 + 100);
        }
        param_1 = param_1 + iVar5;
        uVar7 = uVar7 + iVar5;
        iVar8 = iVar8 + 1;
        puVar6 = puVar6 + 3;
        pfVar10 = pfVar10 + 3;
      } while (iVar8 < (int)(uint)*(byte *)(iVar4 + 0x8b));
    }
    return iVar8;
  }
  return 0;
}

