/* Ghidra analysis pseudocode, not original source.
 * ev_469f0313f1021f0e4bd926e538674038e4b9c059f1b4f78e0c32d78ee9f9f283
 * Entry: 0x4d9280; label: FUN_004d9280
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d9280(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  if (DAT_00951b50 == 0) {
    iVar1 = FUN_005cfac0(&DAT_00881cc8);
    if (iVar1 != 0) {
      puVar3 = &DAT_00881cd8;
      iVar1 = 0x40;
      do {
        if (puVar3[-1] != 0) {
          local_4c = puVar3[4];
          local_48 = local_4c;
          local_44 = local_4c;
          FUN_005b45a0(local_40,&local_4c);
          FUN_005b4900(local_40,puVar3);
          FUN_005b4dd0(local_40,*(undefined2 *)(puVar3 + 5));
          FUN_005b5060(local_40,*(undefined2 *)((int)puVar3 + 0x16));
          FUN_005f33b0(&DAT_00881cc8,local_40);
        }
        puVar3 = puVar3 + 7;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      return;
    }
  }
  else {
    bVar4 = 0;
    puVar3 = &DAT_008824c8;
    do {
      uVar2 = 1 << (bVar4 & 0x1f);
      if ((uVar2 & _DAT_008827c8) != 0 || ((int)uVar2 >> 0x1f & _DAT_008827cc) != 0) {
        FUN_005b44e0(local_40);
        FUN_005b4900(local_40,puVar3);
        FUN_005f33b0(&DAT_00881cc8,local_40);
      }
      puVar3 = puVar3 + 3;
      bVar4 = bVar4 + 1;
    } while ((int)puVar3 < 0x8827c8);
  }
  return;
}

