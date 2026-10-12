/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5dece0; label: FUN_005dece0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005dece0(void)

{
  if (DAT_009739b0 != 0) {
    DAT_0080ba64 = DAT_009739b0 + -1;
    DAT_009739b0 = 0;
    DAT_00973fc4 = 1;
    DAT_0096d938 = FUN_004fa5f0("dlist.htm",1);
    DAT_0096e574 = &DAT_009720b8;
    DAT_00971890 = &DAT_00972cb8;
    DAT_00973968 = DAT_0096d938;
    FUN_005d7230("<body bgcolor=#C0C0C0>");
  }
  return;
}

