/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c5460; label: FUN_004c5460
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c5460(void)

{
  FUN_004c5300(_DAT_0087c548,0x3f800000,1,_DAT_007fcc70 + _DAT_0087bf1c,0,_DAT_008804a0 & 0xffff,0);
  FUN_004c5020(&DAT_00880164,_DAT_0087c54c,_DAT_008804bc + _DAT_0087bf20,0,_DAT_008804a0 & 0xffff,0)
  ;
  FUN_004c5300(_DAT_0087c550,0x3f800000,1,_DAT_007fcc6c + _DAT_0087bf24,0,_DAT_008804a0 & 0xffff,0);
  FUN_004c51f0(&DAT_0087c520,&DAT_0088017c,_DAT_0087c554,0x3f800000,_DAT_007fcc68 + _DAT_0087bf28,0,
               _DAT_008804a0 & 0xffff,0);
  FUN_004c5300(_DAT_0087c554,0x3f800000,0,_DAT_007fcc68 + _DAT_0087bf28,0,_DAT_008804a0 & 0xffff,0);
  FUN_004c53d0(&DAT_00880188,_DAT_0087c558,_DAT_007fcc64 + _DAT_0087bf2c,0,_DAT_008804a0 + 0x2000,0)
  ;
  FUN_004c5300(_DAT_0087c55c,0x3f800000,1,_DAT_0087bf30,0,_DAT_008804a0 & 0xffff,0);
  return;
}

