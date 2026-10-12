/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dab40; label: thunk_FUN_004d9280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_004d9280(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 auStack_40 [64];
  
  if (DAT_00951b50 == 0) {
    iVar1 = FUN_005cfac0(&DAT_00881cc8);
    if (iVar1 != 0) {
      puVar3 = &DAT_00881cd8;
      iVar1 = 0x40;
      do {
        if (puVar3[-1] != 0) {
          uStack_4c = puVar3[4];
          uStack_48 = uStack_4c;
          uStack_44 = uStack_4c;
          FUN_005b45a0(auStack_40,&uStack_4c);
          FUN_005b4900(auStack_40,puVar3);
          FUN_005b4dd0(auStack_40,*(undefined2 *)(puVar3 + 5));
          FUN_005b5060(auStack_40,*(undefined2 *)((int)puVar3 + 0x16));
          FUN_005f33b0(&DAT_00881cc8,auStack_40);
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
        FUN_005b44e0(auStack_40);
        FUN_005b4900(auStack_40,puVar3);
        FUN_005f33b0(&DAT_00881cc8,auStack_40);
      }
      puVar3 = puVar3 + 3;
      bVar4 = bVar4 + 1;
    } while ((int)puVar3 < 0x8827c8);
  }
  return;
}

