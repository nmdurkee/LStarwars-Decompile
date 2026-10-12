/* Ghidra pseudocode, not original source.
 * ev_92748b398136944cd3b8ebaa69598612f81b868998f444146461847577bf6b2d
 * Entry: 0x6de8d0; label: FUN_006de8d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006de8d0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((param_1 + 3U & 0xfffffffc) + ((uint)(PTR_DAT_00827730 + 3) & 0xfffffffc))
  ;
  *puVar1 = PTR_DAT_00827730;
  PTR_DAT_00827730 = (undefined *)(puVar1 + 1);
  return;
}

