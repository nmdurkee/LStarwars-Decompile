/* Ghidra pseudocode, not original source.
 * ev_9a76e25c08ce4dcda3c08de929e5a103c2765ccb900e87aba0770623e17ea5fe
 * Entry: 0x6df940; label: FUN_006df940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006df940(void)

{
  int iVar1;
  
  FUN_004ffaa0(DAT_0297ae20);
  FUN_006e5340(0x89,0);
  FUN_006e5340(7,1);
  FUN_006e5340(0xe,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x13,2);
  FUN_006e5340(0x14,1);
  FUN_006e5340(0x18,0);
  FUN_006e5340(0x19,8);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(0x34,0);
  iVar1 = 0;
  do {
    FUN_006e54e0(iVar1,5,2);
    FUN_006e54e0(iVar1,6,2);
    FUN_006e54e0(iVar1,7,2);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  FUN_006e5630(0,0);
  FUN_006e5630(1,0);
  FUN_006e5340(0x16,1);
  FUN_006e5670(1,1,1);
  FUN_006e5670(1,4,1);
  FUN_004ffac0(DAT_0297ae20);
  return;
}

