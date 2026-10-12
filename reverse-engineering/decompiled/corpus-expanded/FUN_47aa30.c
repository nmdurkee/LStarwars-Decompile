/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47aa30; label: FUN_0047aa30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047aa30(void)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  
  DAT_00879524 = (undefined2)DAT_00802bdc;
  DAT_00879520 = (undefined2)DAT_00802bd8;
  _DAT_00879522 = 1;
  _DAT_00879526 = 1;
  iVar2 = 2;
  if ((DAT_00951364 != 0) &&
     (psVar3 = *(short **)(DAT_00951364 + 0x98), iVar2 = 2, iVar1 = 2, psVar3 != (short *)0x0)) {
    do {
      iVar2 = iVar1;
      if (*psVar3 == -1) break;
      (&DAT_00879520)[iVar2 * 2] = *psVar3;
      *(undefined2 *)(&DAT_00879522 + iVar2 * 4) = 1;
      iVar2 = iVar2 + 1;
      psVar3 = psVar3 + 1;
      iVar1 = iVar2;
    } while (iVar2 < 5);
  }
  (&DAT_00879520)[iVar2 * 2] = 0xffff;
  DAT_0093d590._0_2_ = DAT_00879520;
  DAT_0093d590._2_2_ = DAT_00879524;
  _DAT_0093d594 = 0xffff;
  return;
}

