/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63bdf0; label: FUN_0063bdf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0063bdf0(float param_1)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  undefined4 *puVar4;
  int in_EAX;
  float *pfVar5;
  int iVar6;
  float10 fVar7;
  
  _DAT_02913988 = 1;
  if ((*(uint *)(in_EAX + 0x78) & *(uint *)(DAT_0080fea4 * 0x20 + 0x80feb8)) != 0) {
    DAT_029139a0 = 1;
    FUN_006382a0();
  }
  if (DAT_029139a0 == 0) {
    if ((*(uint *)(in_EAX + 0x70) & *(uint *)(DAT_0080fea4 * 0x20 + 0x80febc)) == 0) {
      FUN_00620e70();
      FUN_00620fa0(&DAT_029134a4,&DAT_029134fc,&DAT_02913694);
      fVar7 = (float10)FUN_00621050();
      fVar1 = _DAT_0080feec * ABS((float)fVar7);
      if (fVar1 < 1.0) {
        fVar1 = 1.0;
      }
      if (((DAT_029139b8 == 0) || (*(int *)(in_EAX + 0x70) == 0)) &&
         ((DAT_029139b8 = 0, DAT_029139b4 == 0 || (*(int *)(in_EAX + 0x70) == 0)))) {
        DAT_029139b4 = 0;
        if ((*(uint *)(in_EAX + 0x78) & 0x800) != 0) {
          return 1;
        }
        if (DAT_02913a1c != 0) {
          if ((*(uint *)(in_EAX + 0x70) & *(uint *)(DAT_0080fea4 * 0x20 + 0x80feb0)) == 0) {
            DAT_029139b4 = 0;
            DAT_029139b8 = 0;
            DAT_02913a1c = 0;
            return 0;
          }
          FUN_005b3800(&DAT_02913a04,&DAT_029134a4,&DAT_02913a10);
          FUN_005b37d0(DAT_02913a00 + 8,DAT_02913a00 + 8,&DAT_02913a04);
          _DAT_02913a14 = DAT_029134a8;
          _DAT_02913a10 = DAT_029134a4;
          _DAT_02913a18 = DAT_029134ac;
          pfVar5 = (float *)(DAT_02913814 + 7);
          fVar3 = (float)(int)((uint)*(byte *)(in_EAX + 0x94) - (uint)*(byte *)(in_EAX + 0x95)) *
                  _DAT_0080fee8 * fVar1 * param_1 + *pfVar5;
          *pfVar5 = fVar3;
          fVar1 = _DAT_0080fef0;
          if (_DAT_0080fef0 <= fVar3) {
            fVar1 = *pfVar5;
          }
          *pfVar5 = fVar1;
          return 0;
        }
        DAT_02913814 = (undefined4 *)FUN_0063bae0();
        uVar2 = *(uint *)(in_EAX + 0x78);
        iVar6 = DAT_0080fea4 * 0x20;
        if ((*(uint *)(iVar6 + 0x80fea8) & uVar2) == 0) {
          if (DAT_02913814 != (undefined4 *)0x0) {
            if ((*(uint *)(iVar6 + 0x80feb0) & uVar2) == 0) {
              if ((*(uint *)(iVar6 + 0x80feac) & uVar2) != 0) {
                FUN_00637fc0(DAT_02913814);
              }
            }
            else {
              _DAT_02913a10 = DAT_029134a4;
              DAT_02913a1c = 1;
              _DAT_02913a14 = DAT_029134a8;
              _DAT_02913a18 = DAT_029134ac;
              DAT_02913a00 = DAT_02913814;
            }
          }
        }
        else {
          DAT_02913814 = (undefined4 *)FUN_00637f90();
          if (DAT_02913814 != (undefined4 *)0x0) {
            DAT_02913814[5] = 1;
            puVar4 = DAT_02913814;
            DAT_02913814[8] = DAT_029134a4;
            puVar4[9] = DAT_029134a8;
            puVar4[10] = DAT_029134ac;
            DAT_02913814[7] = _DAT_0080fef0;
            *DAT_02913814 = 0x41200000;
            DAT_02913814[1] = 0x42c80000;
            DAT_02913814[0xc] = 0x41200000;
            DAT_02913814[0xd] = 0x42c80000;
            DAT_02913814[2] = 0x80808080;
            DAT_02913814[3] = 0;
            DAT_02913814[4] = 0;
            DAT_02913814[0xb] = 0;
            DAT_02913814[0xf] = 0;
            *(undefined1 *)(DAT_02913814 + 6) = 1;
          }
        }
        if ((*(uint *)(in_EAX + 0x78) & 0x4000) != 0) {
          DAT_0291397c = 1;
        }
        if ((*(uint *)(in_EAX + 0x78) & 0x1000) != 0) {
          DAT_02913980 = 1 - DAT_02913980;
        }
      }
    }
    else {
      if (DAT_02913814 != (undefined4 *)0x0) {
        FUN_00620f10(DAT_02913814 + 8);
      }
      if ((*(uint *)(DAT_0080fea4 * 0x20 + 0x80fec4) & *(uint *)(in_EAX + 0x78)) == 0) {
        if ((*(uint *)(DAT_0080fea4 * 0x20 + 0x80fec0) & *(uint *)(in_EAX + 0x78)) == 0) {
          return 0;
        }
        DAT_02913814 = (undefined4 *)FUN_0063bd20();
      }
      else {
        DAT_02913814 = (undefined4 *)FUN_0063bd80();
      }
      if (DAT_02913814 != (undefined4 *)0x0) {
        FUN_00620f10(DAT_02913814 + 8);
        return 0;
      }
    }
  }
  else {
    FUN_0062a400(DAT_0291353c,param_1);
    if (DAT_029139a0 == 0) {
      DAT_029139b8 = 1;
      DAT_02913a1c = 0;
      return 0;
    }
  }
  return 0;
}

