/* Ghidra analysis pseudocode, not original source.
 * ev_528f0eafdf60551b868e0e925a842777892bdaf44669a30da4d03ef81027d70b
 * Entry: 0x6de8d0; label: FUN_006de8d0
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

