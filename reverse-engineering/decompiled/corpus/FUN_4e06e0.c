/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e06e0; label: FUN_004e06e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e06e0(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  _DAT_00889480 = 0;
  _DAT_0088946c = 0;
  _DAT_00889470 = 0;
  _DAT_00889474 = 0;
  _DAT_00889478 = 0;
  DAT_0088947d = 0;
  DAT_0088947e = 0xff;
  DAT_0088947f = 0xff;
  DAT_00889484 = 0;
  DAT_00882b74[1] = 0;
  DAT_00882b74[3] = 0;
  DAT_00882b74[2] = 0;
  DAT_00882b74[4] = 0;
  *DAT_00882b74 = 0xffff;
  *(undefined1 *)(DAT_00882b74 + 6) = 0;
  iVar3 = 0;
  if ('\0' < DAT_0088947c) {
    puVar1 = &DAT_0088916c;
    do {
      FUN_005cfc00(puVar1 + -0xc0,1);
      FUN_005cfc00(puVar1,0);
      FUN_005cfc00(puVar1 + 0x180,0);
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 0xc;
    } while (iVar3 < DAT_0088947c);
  }
  DAT_00889488 = FUN_005ab050(DAT_0095df4c,"NextDiscoTile",0,0);
  DAT_0088948c = FUN_005ab050(DAT_0095df4c,"DiscoComplete",0,0);
  puVar2 = &DAT_0088908c;
  puVar1 = &DAT_00882b78;
  do {
    FUN_005cfc00(puVar1,0);
    if (DAT_00951b50 == 0) {
      FUN_0055a2b0(*(undefined4 *)(param_1 + 0x2ac8),*puVar2,1,0);
      if (*(int *)(*(int *)(*(int *)*puVar2 + 0x28) + 0xc) == 0) {
        FUN_0055a250(*(undefined4 *)(param_1 + 0x2ac8),(int *)*puVar2,1,0);
      }
    }
    puVar1 = puVar1 + 0xc;
    puVar2 = puVar2 + 1;
  } while ((int)puVar1 < 0x882b9c);
  return;
}

