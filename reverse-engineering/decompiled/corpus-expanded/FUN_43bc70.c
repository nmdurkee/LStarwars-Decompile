/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43bc70; label: FUN_0043bc70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0043bc70(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar1 = PTR_s_Batman_007f6754;
  while( true ) {
    if (puVar1 == (undefined *)0x0) {
      return 0;
    }
    iVar2 = FUN_004f8b10();
    if (iVar2 == 0) break;
    iVar3 = iVar3 + 1;
    puVar1 = (&PTR_s_Batman_007f6754)[iVar3];
  }
  return 1;
}

