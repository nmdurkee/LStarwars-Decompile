/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x63b2d0; label: FUN_0063b2d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063b2d0(float param_1,int param_2)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  float10 fVar7;
  undefined1 auStack_bc [3];
  char local_b9;
  float local_b8;
  uint local_b4;
  uint local_b0;
  undefined1 local_ac [12];
  undefined4 local_a0 [15];
  float local_64;
  float local_60;
  short local_46;
  short local_44;
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)auStack_bc;
  DAT_029139d4 = 0;
  if (DAT_029139a4 != 0) {
    FUN_0062a400(DAT_029137b0,param_1,param_2);
    __security_check_cookie(local_c ^ (uint)auStack_bc);
    return;
  }
  if (DAT_029139a0 == 0) {
    if ((*(uint *)(param_2 + 0x78) & *(uint *)(DAT_0080fea4 * 0x20 + 0x80feb8)) != 0) {
      DAT_029139a0 = 1;
      FUN_006382a0();
      __security_check_cookie(local_c ^ (uint)auStack_bc);
      return;
    }
    if ((*(uint *)(param_2 + 0x70) & *(uint *)(DAT_0080fea4 * 0x20 + 0x80febc)) == 0) {
      FUN_00620fa0(local_ac,0,0);
      FUN_00621050();
      FUN_00620e70(param_2,param_1);
      local_b4 = DAT_02913694 & 0xffff;
      local_b0 = DAT_029134fc & 0xffff;
      FUN_00620fa0(&DAT_029134a4,&DAT_029134fc,&DAT_02913694);
      fVar7 = (float10)FUN_00621050();
      puVar6 = DAT_029139bc;
      local_b8 = _DAT_0080feec * ABS((float)fVar7);
      if (local_b8 < 1.0) {
        local_b8 = 1.0;
      }
      if (((DAT_029139b8 == 0) || (*(int *)(param_2 + 0x70) == 0)) &&
         ((DAT_029139b8 = 0, DAT_029139b4 == 0 || (*(int *)(param_2 + 0x70) == 0)))) {
        DAT_029139b4 = 0;
        if ((*(uint *)(param_2 + 0x78) & 0x800) != 0) {
          __security_check_cookie(local_c ^ (uint)auStack_bc);
          return;
        }
        DAT_029139d4 = 1;
        if (DAT_029139fc != 0) {
          DAT_029139d4 = 2;
          if ((*(uint *)(param_2 + 0x70) & *(uint *)(DAT_0080fea4 * 0x20 + 0x80feb0)) != 0) {
            puVar6 = DAT_029139f8;
            puVar4 = local_a0;
            for (iVar5 = 0x23; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar4 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar4 = puVar4 + 1;
            }
            FUN_005b3800(&DAT_029139e0,&DAT_029134a4,&DAT_029139ec);
            FUN_005b37d0(local_a0,local_a0,&DAT_029139e0);
            _DAT_029139f0 = DAT_029134a8;
            _DAT_029139ec = DAT_029134a4;
            _DAT_029139f4 = DAT_029134ac;
            sVar2 = (short)local_b0;
            local_46 = local_46 + ((short)DAT_029134fc - sVar2);
            sVar3 = (short)local_b4;
            local_44 = local_44 + ((short)DAT_02913694 - sVar3);
            FUN_00620f40((int)sVar2,(int)sVar3);
            local_a0[3] = 0;
            local_a0[4] = 0;
            local_a0[5] = 0x3f800000;
            DAT_029134fc = (int)sVar2;
            DAT_02913694 = (int)sVar3;
            FUN_005b35a0(local_a0 + 3,local_a0 + 3,(int)local_46);
            FUN_005b3620(local_a0 + 3,local_a0 + 3,(int)local_44);
            local_b4 = (uint)*(byte *)(param_2 + 0x96) - (uint)*(byte *)(param_2 + 0x97);
            local_64 = local_64 +
                       param_1 * local_b8 *
                                 _DAT_0080fee8 *
                                 (float)(int)((uint)*(byte *)(param_2 + 0x94) -
                                             (uint)*(byte *)(param_2 + 0x95));
            local_60 = local_b8 * (float)(int)local_b4 * _DAT_0080fee8 * param_1 + local_60;
            if (local_64 < _DAT_0080fef0) {
              local_64 = _DAT_0080fef0;
            }
            if (local_60 < local_64) {
              local_60 = local_64;
            }
            if ((DAT_008100fc != 0) && (iVar5 = FUN_006379f0(local_a0), iVar5 != 0)) {
              FUN_006378f0();
              DAT_008100fc = 0;
            }
            puVar6 = local_a0;
            puVar4 = DAT_029139f8;
            for (iVar5 = 0x23; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar4 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar4 = puVar4 + 1;
            }
            __security_check_cookie(local_c ^ (uint)auStack_bc);
            return;
          }
          goto LAB_0063b362;
        }
        puVar4 = DAT_029139bc;
        if (DAT_029139bc == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)FUN_0063ae40();
        }
        DAT_02913824 = puVar4;
        if ((DAT_02913818 == (undefined4 *)0x0) || ((*(uint *)(param_2 + 0x78) & 0x8000) == 0)) {
          uVar1 = *(uint *)(param_2 + 0x78);
          iVar5 = DAT_0080fea4 * 0x20;
          if ((*(uint *)(iVar5 + 0x80fea8) & uVar1) == 0) {
            if (puVar4 != (undefined4 *)0x0) {
              DAT_029139d4 = (*(char *)((int)puVar4 + 0x7a) != -1) + 3;
              if ((*(uint *)(iVar5 + 0x80feb0) & uVar1) == 0) {
                if ((*(uint *)(iVar5 + 0x80feac) & uVar1) == 0) {
                  if ((*(uint *)(iVar5 + 0x80feb4) & uVar1) == 0) {
                    if ((uVar1 & 0x8000) != 0) {
                      if (DAT_02913818 == (undefined4 *)0x0) {
                        DAT_02913818 = puVar4;
                      }
                      DAT_029139bc = (undefined4 *)0x0;
                    }
                  }
                  else {
                    DAT_029139bc = (undefined4 *)
                                   (~-(uint)(puVar6 != (undefined4 *)0x0) & (uint)puVar4);
                  }
                }
                else {
                  DAT_029139a4 = 1;
                  DAT_029137b0[2] = *DAT_029137b0;
                }
              }
              else {
                DAT_029139fc = 1;
                DAT_008100fc = 1;
                _DAT_029139ec = DAT_029134a4;
                _DAT_029139f0 = DAT_029134a8;
                _DAT_029139f4 = DAT_029134ac;
                DAT_029139f8 = puVar4;
              }
            }
          }
          else {
            FUN_006378f0();
            DAT_02913824 = (undefined4 *)FUN_00637e10();
            if (DAT_02913824 != (undefined4 *)0x0) {
              DAT_029139bc = (undefined4 *)0x0;
              *DAT_02913824 = DAT_029134a4;
              DAT_02913824[1] = DAT_029134a8;
              DAT_02913824[2] = DAT_029134ac;
              DAT_02913824[0xf] = _DAT_0080fef0;
              DAT_02913824[0x10] = _DAT_0080fef4;
              DAT_02913824[9] = 0x3f800000;
              DAT_02913824[10] = 0x3f800000;
              DAT_02913824[0xb] = 0x3f800000;
              DAT_02913824[0xc] = 0x3f000000;
              DAT_02913824[0xd] = 0x3f000000;
              DAT_02913824[0xe] = 0x3f000000;
              *(undefined1 *)(DAT_02913824 + 0x16) = 2;
              *(byte *)((int)DAT_02913824 + 0x59) = *(byte *)((int)DAT_02913824 + 0x59) & 0xfe;
              *(undefined2 *)((int)DAT_02913824 + 0x5e) = 0;
              *(undefined2 *)(DAT_02913824 + 0x18) = 0;
              DAT_02913824[0x11] = 0x3dcccccd;
              DAT_02913824[0x12] = 0x3dcccccd;
              DAT_02913824[0x13] = 0x3dcccccd;
              DAT_02913824[0x14] = 0x3dcccccd;
              DAT_02913824[0x15] = 0;
              *(undefined2 *)((int)DAT_02913824 + 0x5a) = 0;
              *(undefined2 *)(DAT_02913824 + 0x17) = 0;
              puVar6 = DAT_02913824;
              DAT_02913824[3] = 0;
              DAT_02913824[4] = 0;
              DAT_02913824[5] = 0x3f800000;
              DAT_02913824[0x19] = 0;
              FUN_005b35a0(puVar6 + 3,puVar6 + 3,(int)*(short *)((int)DAT_02913824 + 0x5a));
              FUN_005b3620(DAT_02913824 + 3,DAT_02913824 + 3,(int)*(short *)(DAT_02913824 + 0x17));
              *(undefined1 *)((int)DAT_02913824 + 0x79) = 0xff;
              *(undefined1 *)((int)DAT_02913824 + 0x7a) = 0xff;
              *(undefined1 *)((int)DAT_02913824 + 0x7b) = 0;
              DAT_02913824[0x1f] = DAT_0291389c + 4;
              if (DAT_02913818 != (undefined4 *)0x0) {
                puVar6 = DAT_02913818;
                puVar4 = DAT_02913824;
                for (iVar5 = 0x23; iVar5 != 0; iVar5 = iVar5 + -1) {
                  *puVar4 = *puVar6;
                  puVar6 = puVar6 + 1;
                  puVar4 = puVar4 + 1;
                }
                *(undefined1 *)((int)DAT_02913824 + 0x79) =
                     *(undefined1 *)((int)DAT_02913818 + 0x79);
                local_b9 = *(char *)((int)DAT_02913824 + 0x79);
                if (local_b9 != -1) {
                  iVar5 = (int)DAT_02913824 + (-4 - DAT_0291389c);
                  *(char *)(local_b9 * 0x8c + 0x7e + DAT_0291389c) =
                       (char)(iVar5 / 0x8c) - (char)(iVar5 / -0x74000000);
                }
                iVar5 = (int)DAT_02913818 + (-4 - DAT_0291389c);
                *(char *)((int)DAT_02913824 + 0x7a) =
                     (char)(iVar5 / 0x8c) - (char)(iVar5 / -0x74000000);
                iVar5 = (int)DAT_02913824 + (-4 - DAT_0291389c);
                *(char *)((int)DAT_02913818 + 0x79) =
                     (char)(iVar5 / 0x8c) - (char)(iVar5 / -0x74000000);
              }
            }
          }
        }
        else {
          FUN_00620f10(DAT_02913818);
          DAT_02913818 = (undefined4 *)0x0;
          DAT_029139bc = (undefined4 *)0x0;
        }
        if ((*(uint *)(param_2 + 0x78) & 0x4000) != 0) {
          DAT_02913814 = 0;
          _DAT_0291397c = 2;
        }
      }
    }
    else {
      DAT_029139d4 = 5;
      FUN_00620fa0(&DAT_029134a4,&DAT_029134fc,&DAT_02913694);
      if (DAT_02913824 == (undefined4 *)0x0) {
        DAT_02913824 = (undefined4 *)FUN_0063ae40();
      }
      else {
        FUN_00620f10(DAT_02913824);
        if ((*(uint *)(DAT_0080fea4 * 0x20 + 0x80fec4) & *(uint *)(param_2 + 0x78)) == 0) {
          if ((*(uint *)(DAT_0080fea4 * 0x20 + 0x80fec0) & *(uint *)(param_2 + 0x78)) != 0) {
            FUN_0063b1e0();
          }
        }
        else {
          FUN_0063b0f0();
        }
      }
      if (DAT_029139bc != (undefined4 *)0x0) {
        DAT_029139bc = DAT_02913824;
        __security_check_cookie(local_c ^ (uint)auStack_bc);
        return;
      }
    }
  }
  else {
    FUN_0062a400(DAT_029137ac,param_1,param_2);
    if (DAT_029139a0 == 0) {
      DAT_029139b8 = 1;
LAB_0063b362:
      DAT_029139fc = 0;
      __security_check_cookie(local_c ^ (uint)auStack_bc);
      return;
    }
  }
  __security_check_cookie(local_c ^ (uint)auStack_bc);
  return;
}

