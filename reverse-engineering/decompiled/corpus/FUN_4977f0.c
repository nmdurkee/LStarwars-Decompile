/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x4977f0; label: FUN_004977f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004977f0(int param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = FUN_0055ce20((int)**(short **)(param_1 + 4),0,0,1,0);
  if ((3.0 <= *(float *)(param_1 + 8)) && (iVar2 = FUN_00574e20(), iVar2 != 9)) {
    if (iVar1 == 0) {
      uVar6 = 0;
      uVar5 = 0;
      if (0 < DAT_0093d500) {
        puVar3 = (uint *)(DAT_0093d504 + 0x1fc);
        uVar6 = 0;
        iVar1 = DAT_0093d500;
        do {
          if (((((*puVar3 & 1) != 0) && ((*puVar3 & 0x1000) != 0)) &&
              (*(char *)((int)puVar3 + 0x8f) == '\0')) && ((char)puVar3[0x21] == -1)) {
            uVar6 = uVar6 | puVar3[-5];
            uVar5 = uVar5 | puVar3[-4];
          }
          puVar3 = puVar3 + 0x436;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
    }
    else {
      uVar6 = *(uint *)(iVar1 + 0x1e8);
      uVar5 = *(uint *)(iVar1 + 0x1ec);
    }
    piVar4 = &DAT_0093d7f0;
    do {
      iVar1 = *piVar4;
      if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) &&
         ((*(uint *)(iVar1 + 0x1f0) & uVar6) != 0 || (*(uint *)(iVar1 + 500) & uVar5) != 0)) {
        if (DAT_00951b50 != 0) {
          return;
        }
        *(undefined1 *)(param_1 + 0x1d) = 2;
        iVar1 = FUN_0054fa60();
        FUN_0042b6f0((int)(iVar1 + (iVar1 >> 0x1f & 0x7fffU)) >> 0xf);
        if (((&DAT_0093d7f0)[DAT_007f3b14] == 0) ||
           ((*(byte *)((&DAT_0093d7f0)[DAT_007f3b14] + 0x1fc) & 0x80) == 0)) {
          DAT_007f3b14 = (uint)(DAT_007f3b14 == 0);
        }
        _DAT_0086e71c = 0;
        FUN_00509830(9,0xffffffff,0xffffffff);
        FUN_00560b40();
        return;
      }
      piVar4 = piVar4 + 1;
    } while ((int)piVar4 < 0x93d810);
  }
  return;
}

