/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x520220; label: FUN_00520220
 */

uint FUN_00520220(int param_1,int param_2,uint param_3,float param_4,undefined4 param_5,
                 float param_6,int param_7)

{
  int iVar1;
  uint in_EAX;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  float local_10;
  undefined1 local_c [12];
  
  local_10 = 3.4028235e+38;
  if (((param_2 != 0) && (in_EAX = param_3, param_3 != 0)) && (*(int *)(param_3 + 4) != 0)) {
    in_EAX = (uint)(ushort)((ushort)(param_4 < 0.0) << 8 | (ushort)NAN(param_4) << 10 |
                           (ushort)(param_4 == 0.0) << 0xe);
    if (param_4 >= 0.0 && (param_4 == 0.0) == 0) {
      local_10 = param_4 * param_4;
    }
    if (param_7 != 0) {
      in_EAX = FUN_0051fe60(param_1,param_2);
    }
    uVar3 = 0;
    iVar5 = 0;
    if ('\0' < *(char *)(param_2 + 0x10)) {
      do {
        if (((param_7 == 0) || (*(char *)(iVar5 + *(int *)(param_2 + 0x18)) == -1)) &&
           ((iVar1 = *(int *)(param_1 + 0x28) +
                     (uint)*(byte *)(*(int *)(param_2 + 0x14) + iVar5) * 0x3c, param_6 == 0.0 ||
            (in_EAX = FUN_005d6620(iVar1 + 0x10,param_6,&DAT_00806680), in_EAX != 0)))) {
          fVar6 = (float10)FUN_005b3c50(param_5,iVar1 + 0x10,local_c);
          fVar7 = (float10)local_10;
          in_EAX = (uint)(ushort)((ushort)(fVar7 < fVar6) << 8 |
                                  (ushort)(NAN(fVar7) || NAN(fVar6)) << 10 |
                                 (ushort)(fVar7 == fVar6) << 0xe);
          if (fVar7 >= fVar6) {
            uVar3 = uVar3 + 1;
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(char *)(param_2 + 0x10));
      if (uVar3 != 0) {
        uVar2 = FUN_005b9e30();
        in_EAX = uVar2 / uVar3;
        uVar4 = 0;
        iVar5 = 0;
        if ('\0' < *(char *)(param_2 + 0x10)) {
          do {
            if ((param_7 == 0) || (*(char *)(iVar5 + *(int *)(param_2 + 0x18)) == -1)) {
              iVar1 = *(int *)(param_1 + 0x28) +
                      (uint)*(byte *)(*(int *)(param_2 + 0x14) + iVar5) * 0x3c;
              fVar6 = (float10)FUN_005b3c50(param_3 + 0x5c,iVar1 + 0x10,local_c);
              fVar7 = (float10)local_10;
              in_EAX = (uint)(ushort)((ushort)(fVar7 < fVar6) << 8 |
                                      (ushort)(NAN(fVar7) || NAN(fVar6)) << 10 |
                                     (ushort)(fVar7 == fVar6) << 0xe);
              if (fVar7 >= fVar6) {
                if (uVar2 % uVar3 == uVar4) {
                  *(int *)(*(int *)(param_3 + 4) + 0xa4) = iVar1;
                  *(undefined1 *)(iVar5 + *(int *)(param_2 + 0x18)) =
                       *(undefined1 *)(param_3 + 0x28d);
                  return param_3;
                }
                uVar4 = uVar4 + 1;
              }
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < *(char *)(param_2 + 0x10));
          return in_EAX;
        }
      }
    }
  }
  return in_EAX;
}

