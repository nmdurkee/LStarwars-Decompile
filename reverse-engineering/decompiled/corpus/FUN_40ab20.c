/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40ab20; label: FUN_0040ab20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040ab20(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  float10 fVar8;
  undefined4 local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  if (DAT_00951288 == 0) {
    uVar7 = 0;
    do {
      iVar1 = (&DAT_0093d7f0)[uVar7];
      if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) {
        if ((((_DAT_00950780 != 0.0) ||
             ((((*(char *)(iVar1 + 0x28b) != '\0' || (*(char *)(iVar1 + 0x7b5) == '+')) ||
               (0.0 < *(float *)(iVar1 + 0xd60))) ||
              ((iVar5 = FUN_00574e20(), iVar5 != -1 || (*(char *)(iVar1 + 0x7b5) == '\x0f')))))) ||
            (*(int *)(iVar1 + 0xcd0) != 0)) ||
           (((*(byte *)(iVar1 + 0xe24) & 8) == 0 ||
            (((*(byte *)(*(int *)(iVar1 + 0x54) + 4) & 0x40) != 0 &&
             (0.0 < *(float *)(iVar1 + 0xd38))))))) {
          *(uint *)(iVar1 + 0xef0) = *(uint *)(iVar1 + 0xef0) & 0xffe7ffff;
          *(undefined4 *)(iVar1 + 0xee4) = 0;
          *(undefined4 *)(iVar1 + 0xee8) = 0;
        }
        else {
          uVar2 = *(uint *)(iVar1 + 0xef0);
          if ((DAT_00925068 & 1) == uVar7) {
            local_14 = 0.0;
            local_18 = 0;
            iVar5 = FUN_0054fa60();
            local_10 = (float)iVar5 * 1.5259022e-05 * *(float *)(iVar1 + 0x1dc);
            FUN_0054fa60();
            uVar6 = FUN_006e6b90();
            FUN_005b35a0(&local_18,&local_18,uVar6);
            local_14 = (*(float *)(iVar1 + 0x1e0) / *(float *)(iVar1 + 0x1dc)) * local_14;
            uVar6 = FUN_0054fa60();
            FUN_005b3620(&local_18,&local_18,uVar6);
            FUN_005b37d0(&local_18,&local_18,iVar1 + 0x80);
            FUN_005b3800(local_c,&local_18,PTR_DAT_008021b4 + 0x11c);
            iVar5 = FUN_0067b430(PTR_DAT_008021b4 + 0x11c,local_c,0,0x3f800000,0,0x1f);
            *(uint *)(iVar1 + 0xef0) =
                 *(uint *)(iVar1 + 0xef0) ^ (iVar5 << 0x13 ^ *(uint *)(iVar1 + 0xef0)) & 0x80000;
          }
          uVar3 = *(uint *)(iVar1 + 0xef0);
          if ((uVar3 >> 0x13 & 1) == (uVar2 >> 0x13 & 1)) {
            if ((*(float *)(iVar1 + 0xee4) < 0.3) &&
               (fVar4 = _DAT_00925018 + *(float *)(iVar1 + 0xee4), *(float *)(iVar1 + 0xee4) = fVar4
               , 0.3 <= fVar4)) {
              *(undefined4 *)(iVar1 + 0xee4) = 0x3e99999a;
              *(uint *)(iVar1 + 0xef0) = (uVar3 * 2 ^ uVar3) & 0x100000 ^ uVar3;
            }
          }
          else {
            *(undefined4 *)(iVar1 + 0xee4) = 0;
          }
        }
        uVar6 = 0;
        if ((*(uint *)(iVar1 + 0xef0) & 0x100000) != 0) {
          uVar6 = 0x3f800000;
        }
        fVar8 = (float10)FUN_0054fad0(*(undefined4 *)(iVar1 + 0xee8),uVar6,_DAT_00925018 * 3.0);
        *(float *)(iVar1 + 0xee8) = (float)fVar8;
      }
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < 2);
  }
  return;
}

