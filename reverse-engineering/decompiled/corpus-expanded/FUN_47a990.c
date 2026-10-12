/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47a990; label: FUN_0047a990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047a990(int *param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = (int)*(char *)(*param_1 + 0xa3);
  if (iVar2 != -1) {
    if (DAT_008795a0 != iVar2) {
      *param_1 = 0;
      return;
    }
    FUN_00496740();
    DAT_00879588 = (int)*(short *)(iVar2 * 0x9c + 0x60 + DAT_00951354);
    *param_1 = 0;
    _DAT_00879574 = 0;
    _DAT_00879508 = 0;
    _DAT_0095067c = 0;
    FUN_00565be0(1);
    FUN_00564780();
    bVar1 = *(byte *)(iVar2 * 0x9c + 0x7a + DAT_00951354);
    FUN_005765b0();
    FUN_00509830(((bVar1 & 4) != 0) + '\x0f',0xffffffff,0xffffffff);
  }
  return;
}

