/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d6f30; label: FUN_005d6f30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d6f30(int param_1)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint _Size;
  undefined *_Dst;
  byte *pbVar6;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if ((((*(float *)(iVar1 + 8) <= DAT_00973718) && (DAT_00973718 <= *(float *)(iVar1 + 0xc))) &&
      (*(float *)(iVar1 + 0x10) <= DAT_00973720)) && (DAT_00973720 <= *(float *)(iVar1 + 0x14))) {
    iVar4 = FUN_005d6f00((DAT_00973720 - *(float *)(iVar1 + 0x10)) * *(float *)(iVar1 + 0x1c));
    iVar2 = *(int *)(iVar1 + 4);
    iVar5 = FUN_005d6f00((DAT_00973718 - *(float *)(iVar1 + 8)) * *(float *)(iVar1 + 0x18));
    iVar5 = iVar4 * iVar2 + iVar5;
    iVar2 = *(int *)(*(int *)(iVar1 + 0x2c) + iVar5 * 4);
    _DAT_00973960 = (uint)(iVar2 != 0);
    *(int *)(param_1 + 0x24) = iVar2;
    if (((*(int *)(iVar1 + 0x20) == 1) && (*(int *)(param_1 + 0x24) != 0)) &&
       (*(undefined **)(param_1 + 0x24) = &DAT_00966390, iVar5 != DAT_0080b9e4)) {
      iVar2 = *(int *)(iVar1 + 0x24);
      pbVar6 = *(byte **)(*(int *)(iVar1 + 0x2c) + iVar5 * 4);
      DAT_0080b9e4 = iVar5;
      for (_Dst = &DAT_00966390; _Dst < &DAT_00966390 + iVar2; _Dst = _Dst + _Size) {
        _Size = (uint)(*pbVar6 >> 2);
        bVar3 = *pbVar6 & 3;
        pbVar6 = pbVar6 + 1;
        if (bVar3 < 2) {
          _memset(_Dst,(uint)(byte)-bVar3,_Size);
        }
        else {
          FUN_004ef660(_Dst,pbVar6);
          pbVar6 = pbVar6 + _Size;
        }
      }
    }
    return;
  }
  return;
}

