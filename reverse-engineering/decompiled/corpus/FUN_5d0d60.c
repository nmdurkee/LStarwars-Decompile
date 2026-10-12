/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0d60; label: FUN_005d0d60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005d0d60(int param_1,char *param_2)

{
  char cVar1;
  float fVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  float local_c;
  uint local_8;
  float local_4;
  
  if ((param_1 == 0) && (param_1 = DAT_009738b8, DAT_009738b8 == 0)) {
    return (float10)0;
  }
  local_c = 0.0;
  local_4 = **(float **)(param_1 + 0x2c);
  cVar1 = *param_2;
  do {
    if (cVar1 == '\0') {
      return (float10)(_DAT_0080b608 * local_c * local_4);
    }
    param_2 = (char *)FUN_004f2fd0(&local_8,param_2);
    uVar3 = local_8;
    uVar4 = FUN_005d0aa0(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x10),local_8);
    if (uVar4 == 0xffff) {
      uVar4 = FUN_005d0b40(param_1,0x3f);
    }
    uVar5 = (uint)uVar4;
    if ((uVar3 & 0xffff) == 0x20) {
      fVar2 = _DAT_009738b4;
      if (_DAT_009738b4 == 0.0) {
LAB_005d0e39:
        fVar2 = *(float *)(*(int *)(param_1 + 0x34) + 8 + uVar5 * 0xc);
      }
    }
    else if ((uVar3 & 0xffff) - 0x30 < 10) {
      if (((byte)DAT_009738c4 & 1) != 0) {
        uVar5 = FUN_005d0b40(param_1,0x30);
        uVar5 = uVar5 & 0xffff;
        goto LAB_005d0e39;
      }
      fVar2 = *(float *)(*(int *)(param_1 + 0x34) + 8 + uVar5 * 0xc);
    }
    else {
      fVar2 = *(float *)(*(int *)(param_1 + 0x34) + 8 + uVar5 * 0xc);
    }
    cVar1 = *param_2;
    local_c = fVar2 + *(float *)(param_1 + 0x24) + local_c;
  } while( true );
}

