/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x592280; label: FUN_00592280
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00592280(int param_1)

{
  ushort *puVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  if ((DAT_00802860 != -1) && ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2010) == 0)) {
    if (*(char *)(param_1 + 0x7b5) == DAT_00802860) {
      if (*(int *)(PTR_PTR_008040bc + 8) != 0) {
        (**(code **)(PTR_PTR_008040bc + 8))(param_1,param_1 + 0x80);
      }
      if (*(int *)(param_1 + 0x798) != 0) {
        FUN_0058ed40(*(int *)(param_1 + 0x798),param_1);
        if (((*(byte *)(*(int *)(param_1 + 0x798) + 0x72) & 0x80) != 0) && (DAT_0087baf0 == 0)) {
          *(undefined1 *)(param_1 + 0x7b5) = 0xff;
          *(undefined1 *)(*(int *)(param_1 + 0x798) + 0x6e) = 1;
          puVar1 = (ushort *)(*(int *)(param_1 + 0x798) + 0x7a);
          *puVar1 = *puVar1 | 4;
        }
        if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) ==
             0) || (iVar4 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0),
                   iVar4 != 0)) {
          if ((*(char *)(*(int *)(param_1 + 0x798) + 0x6d) != '\0') ||
             (((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_00802280) == 0 ||
              (0.2 <= *(float *)(param_1 + 0x77c))))) {
            fVar2 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
            *(float *)(param_1 + 0x77c) = fVar2;
            if (fVar2 <= 0.0) {
              *(undefined1 *)(param_1 + 0x7b5) = 0xff;
            }
          }
          else {
            *(undefined4 *)(param_1 + 0x77c) = 0x3e4ccccd;
          }
          if (*(char *)(param_1 + 0x7b5) != -1) {
            *(undefined1 *)(*(int *)(param_1 + 0x798) + 0x6e) = 1;
            puVar1 = (ushort *)(*(int *)(param_1 + 0x798) + 0x7a);
            *puVar1 = *puVar1 | 4;
            return;
          }
        }
      }
    }
    else if (((((DAT_00804c74 != -1) &&
               (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c74 * 4) != 0)) &&
              (iVar4 = FUN_0062f150(param_1 + 8,(int)DAT_00804c74,1,1), iVar4 == 0)) &&
             (*(char *)(param_1 + 0x281) != '\0')) &&
            ((iVar4 = FUN_005620f0(param_1), iVar4 != 0 ||
             (iVar4 = FUN_00578790(param_1,DAT_00802860), iVar4 != 0)))) {
      iVar4 = FUN_0058eaa0(PTR_DAT_00802c54,param_1,1,DAT_0087baf0);
      iVar5 = FUN_00578790(param_1,DAT_00802860);
      if ((iVar5 != 0) &&
         (fVar2 = *(float *)(param_1 + 0x77c) - _DAT_00925018, *(float *)(param_1 + 0x77c) = fVar2,
         fVar2 <= 0.0)) {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        *(undefined4 *)(param_1 + 0x7a0) = 0;
      }
      if ((iVar4 != 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) {
        if ((*(char *)(param_1 + 0x281) != '\0') && ((*(byte *)(iVar4 + 0x72) & 4) != 0)) {
          FUN_0058f3f0(param_1,iVar4);
        }
        FUN_0058ed40(iVar4,param_1);
        *(ushort *)(iVar4 + 0x7a) = *(ushort *)(iVar4 + 0x7a) | 4;
        if (((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802280) != 0) ||
           ((iVar5 = FUN_00578790(param_1,DAT_00802860), iVar5 != 0 &&
            ((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_00802280) != 0)))) {
          if ((DAT_009555b0 != (code *)0x0) && (iVar5 = (*DAT_009555b0)(iVar4,param_1), iVar5 == 0))
          {
            return;
          }
          *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_00802860;
          sVar3 = DAT_00804c74;
          *(undefined4 *)(param_1 + 0x77c) = 0x3ecccccd;
          *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xffffbfff;
          *(short *)(param_1 + 0x7aa) = sVar3;
          *(int *)(param_1 + 0x798) = iVar4;
          *(undefined1 *)(param_1 + 0x7b4) = 0;
          FUN_00590be0(iVar4,param_1);
          FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
          FUN_00576960(DAT_00803990);
        }
        if (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) && (*(char *)(param_1 + 0x281) != '\0')) {
          FUN_0058fae0(param_1);
        }
      }
    }
  }
  return;
}

