/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4cc8e0; label: FUN_004cc8e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cc8e0(void)

{
  undefined2 uVar1;
  char cVar2;
  undefined **ppuVar3;
  
  cVar2 = '\0';
  ppuVar3 = &PTR_s_batman_007fcfb8;
  do {
    *(char *)((int)ppuVar3 + 0x16) = cVar2;
    uVar1 = FUN_0055b1c0(*ppuVar3);
    *(undefined2 *)(ppuVar3 + 5) = uVar1;
    ppuVar3 = ppuVar3 + 6;
    cVar2 = cVar2 + '\x01';
  } while ((int)ppuVar3 < 0x7fd0a8);
  return;
}

