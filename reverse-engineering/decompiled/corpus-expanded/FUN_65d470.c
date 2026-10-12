/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65d470; label: FUN_0065d470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065d470(void)

{
  undefined1 *puVar1;
  
  FUN_00543f30();
  puVar1 = &DAT_02947db4;
  do {
    *(undefined4 *)(puVar1 + -0x1c) = 0xffffffff;
    *puVar1 = 0xff;
    puVar1 = puVar1 + 0x44;
  } while ((int)puVar1 < 0x2948eb4);
  DAT_029211c8 = 0;
  _DAT_0292fc3c = 0;
  _DAT_02948ef0 = 0;
  DAT_029211cc = 0;
  DAT_0292fc40 = 0;
  _DAT_02948ef4 = 0;
  _DAT_029211d0 = 0;
  _DAT_0292fc44 = 0;
  _DAT_02948ef8 = 0;
  _DAT_029211d4 = 0;
  _DAT_0292fc48 = 0;
  _DAT_02948efc = 0;
  _DAT_029211d8 = 0;
  _DAT_0292fc4c = 0;
  _DAT_02948f00 = 0;
  _DAT_029211dc = 0;
  _DAT_0292fc50 = 0;
  _DAT_02948f04 = 0;
  _DAT_029211e0 = 0;
  _DAT_0292fc54 = 0;
  _DAT_02948f08 = 0;
  _DAT_029211e4 = 0;
  _DAT_0292fc58 = 0;
  _DAT_02948f0c = 0;
  DAT_02962974 = 0;
  return;
}

