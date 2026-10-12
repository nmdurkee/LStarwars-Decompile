/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e5380; label: FUN_004e5380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e5380(void)

{
  int iVar1;
  undefined1 local_44 [12];
  undefined1 local_38;
  char local_37;
  
  iVar1 = FUN_0055e340(local_44,&local_38);
  if ((iVar1 != 0) && (local_37 != -1)) {
    if ((DAT_0087b1b8 != 0) && (local_37 < '\x06')) {
      DAT_00802c60 = (int)*(short *)(DAT_0087b1b8 + 0x62);
      return;
    }
    if ((DAT_0087b1c0 != 0) && ('\x06' < local_37)) {
      DAT_00802c60 = (int)*(short *)(DAT_0087b1c0 + 0x62);
    }
  }
  return;
}

