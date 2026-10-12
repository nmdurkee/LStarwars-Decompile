/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x495840; label: FUN_00495840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00495840(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((3.0 < _DAT_0092505c != (_DAT_0092505c == 3.0)) && (_DAT_00925064 < 0.666)) {
    uVar2 = _DAT_007facd8;
    if ((DAT_0093b0d8 != 0) && (*(char *)(DAT_0093b0d8 + 0xb) != '\0')) {
      uVar2 = _DAT_007facdc;
    }
    uVar1 = FUN_006e6b90(uVar2);
    FUN_0050d910(PTR_s_FE_Start__00800a68,0,uVar2,0x3f800000,_DAT_0080098c,_DAT_0080098c,
                 _DAT_0080098c,0,0xff,0xff,0xff,0x3fd9999a,1,0,0,uVar1);
  }
  return;
}

