/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f4920; label: FUN_004f4920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f4920(void)

{
  undefined1 *puVar1;
  
  _memset(&DAT_00917000,0,0x840);
  puVar1 = &DAT_00917000;
  do {
    *(undefined4 *)(puVar1 + 4) = 0xffffffff;
    FUN_006d60e0(puVar1);
    puVar1 = puVar1 + 0x84;
  } while ((int)puVar1 < 0x917840);
  _DAT_0297e040 = 0xffffffff;
  DAT_0297e044 = 0xffffffff;
  _DAT_0297e04c = 0xffffffff;
  DAT_0297e050 = 0xffffffff;
  _DAT_0297e058 = 0xffffffff;
  _DAT_0297e05c = 0xffffffff;
  DAT_0297e048 = 0;
  DAT_0297e054 = 0;
  _DAT_0297e060 = 0;
  DAT_0091ef30 = 0;
  return;
}

