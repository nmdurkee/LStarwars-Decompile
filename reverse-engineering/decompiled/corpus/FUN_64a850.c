/* Ghidra analysis pseudocode, not original source.
 * ev_b688fd0177351e281ce3a654852fc29d1d3855db670688278c9fb06d06ddbb68
 * Entry: 0x64a850; label: FUN_0064a850
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064a850(void)

{
  float *pfVar1;
  
  pfVar1 = (float *)&DAT_0291f7c8;
  do {
    if (pfVar1[-5] != -NAN) {
      *pfVar1 = *pfVar1 - 800.0;
      pfVar1[1] = pfVar1[1] - 800.0;
      pfVar1[2] = pfVar1[2] - 800.0;
    }
    if (pfVar1[0x16] != -NAN) {
      pfVar1[0x1b] = pfVar1[0x1b] - 800.0;
      pfVar1[0x1c] = pfVar1[0x1c] - 800.0;
      pfVar1[0x1d] = pfVar1[0x1d] - 800.0;
    }
    if (pfVar1[0x31] != -NAN) {
      pfVar1[0x36] = pfVar1[0x36] - 800.0;
      pfVar1[0x37] = pfVar1[0x37] - 800.0;
      pfVar1[0x38] = pfVar1[0x38] - 800.0;
    }
    if (pfVar1[0x4c] != -NAN) {
      pfVar1[0x51] = pfVar1[0x51] - 800.0;
      pfVar1[0x52] = pfVar1[0x52] - 800.0;
      pfVar1[0x53] = pfVar1[0x53] - 800.0;
    }
    if (pfVar1[0x67] != -NAN) {
      pfVar1[0x6c] = pfVar1[0x6c] - 800.0;
      pfVar1[0x6d] = pfVar1[0x6d] - 800.0;
      pfVar1[0x6e] = pfVar1[0x6e] - 800.0;
    }
    if (pfVar1[0x82] != -NAN) {
      pfVar1[0x87] = pfVar1[0x87] - 800.0;
      pfVar1[0x88] = pfVar1[0x88] - 800.0;
      pfVar1[0x89] = pfVar1[0x89] - 800.0;
    }
    if (pfVar1[0x9d] != -NAN) {
      pfVar1[0xa2] = pfVar1[0xa2] - 800.0;
      pfVar1[0xa3] = pfVar1[0xa3] - 800.0;
      pfVar1[0xa4] = pfVar1[0xa4] - 800.0;
    }
    if (pfVar1[0xb8] != -NAN) {
      pfVar1[0xbd] = pfVar1[0xbd] - 800.0;
      pfVar1[0xbe] = pfVar1[0xbe] - 800.0;
      pfVar1[0xbf] = pfVar1[0xbf] - 800.0;
    }
    if (pfVar1[0xd3] != -NAN) {
      pfVar1[0xd8] = pfVar1[0xd8] - 800.0;
      pfVar1[0xd9] = pfVar1[0xd9] - 800.0;
      pfVar1[0xda] = pfVar1[0xda] - 800.0;
    }
    if (pfVar1[0xee] != -NAN) {
      pfVar1[0xf3] = pfVar1[0xf3] - 800.0;
      pfVar1[0xf4] = pfVar1[0xf4] - 800.0;
      pfVar1[0xf5] = pfVar1[0xf5] - 800.0;
    }
    pfVar1 = pfVar1 + 0x10e;
  } while ((int)pfVar1 < 0x29208a8);
  pfVar1 = (float *)&DAT_02913bc4;
  do {
    if (*(short *)(pfVar1 + -0x37) != -1) {
      *pfVar1 = *pfVar1 - 800.0;
    }
    if (*(short *)(pfVar1 + 0x27) != -1) {
      pfVar1[0x5e] = pfVar1[0x5e] - 800.0;
    }
    if (*(short *)(pfVar1 + 0x85) != -1) {
      pfVar1[0xbc] = pfVar1[0xbc] - 800.0;
    }
    if (*(short *)(pfVar1 + 0xe3) != -1) {
      pfVar1[0x11a] = pfVar1[0x11a] - 800.0;
    }
    if (*(short *)(pfVar1 + 0x141) != -1) {
      pfVar1[0x178] = pfVar1[0x178] - 800.0;
    }
    if (*(short *)(pfVar1 + 0x19f) != -1) {
      pfVar1[0x1d6] = pfVar1[0x1d6] - 800.0;
    }
    if (*(short *)(pfVar1 + 0x1fd) != -1) {
      pfVar1[0x234] = pfVar1[0x234] - 800.0;
    }
    if (*(short *)(pfVar1 + 0x25b) != -1) {
      pfVar1[0x292] = pfVar1[0x292] - 800.0;
    }
    pfVar1 = pfVar1 + 0x2f0;
  } while ((int)pfVar1 < 0x291f7c4);
  _DAT_02920a90 = _DAT_02920a90 - 800.0;
  return;
}

