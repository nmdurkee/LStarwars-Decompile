/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ff750; label: FUN_004ff750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004ff750(int param_1)

{
  HANDLE hFindFile;
  
  FUN_004ef280((&DAT_00921250)[param_1],
               "d:\\projects\\legosagapc\\nu2api.saga\\nucore\\pc\\nufile_pc.c",0x22e);
  hFindFile = *(HANDLE *)(&DAT_0091ef40 + param_1 * 4);
  (&DAT_0092124c)[param_1] = 0;
  FindClose(hFindFile);
  DAT_00921248 = DAT_00921248 + -1;
  return 0;
}

