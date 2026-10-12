/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x4299c0; label: FUN_004299c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004299c0(int param_1)

{
  int iVar1;
  int *piVar2;
  float10 fVar3;
  undefined1 local_18 [4];
  float local_14;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = FUN_0055f450();
  if ((*(int *)(iVar1 + 0x128) == DAT_0087b1f8) && (*(short *)(param_1 + 0x1064) == DAT_007f1990)) {
    piVar2 = &DAT_0093d7f0;
    do {
      iVar1 = *piVar2;
      if (((((iVar1 != 0) && ((*(uint *)(iVar1 + 0x1fc) & 1) != 0)) &&
           ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)) &&
          ((*(char *)(iVar1 + 0x28b) == '\0' && (*(int *)(iVar1 + 0xcd0) == 0)))) &&
         ((FUN_005b3800(&local_c,iVar1 + 0x19c,param_1 + 0x874), _DAT_007f3ae4 < local_8 &&
          ((local_8 < _DAT_007f3ae0 &&
           (local_c * local_c + local_4 * local_4 < _DAT_007f3adc * _DAT_007f3adc)))))) {
        FUN_005b3620(local_18,&DAT_007f3ae8,*(undefined2 *)(param_1 + 0x27a));
        FUN_005b37d0(local_18,local_18,*piVar2 + 0x80);
        fVar3 = (float10)FUN_005506f0(0,local_18,0x40a00000,0xffffffff);
        if ((float)fVar3 != 2e+06) {
          local_14 = (float)fVar3;
        }
        FUN_00561e20(*piVar2,local_18,0,_DAT_007f3af4,_DAT_007f3af8,1);
      }
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0x93d810);
    FUN_00547930(4,param_1 + 0x80,0,0);
  }
  return;
}

