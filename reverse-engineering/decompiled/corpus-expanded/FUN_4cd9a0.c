/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cd9a0; label: FUN_004cd9a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004cd9a0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (&DAT_0093d7f0)[iVar2];
    if (((iVar1 != 0) && (*(char *)(iVar1 + 0x7b5) == 'Q')) &&
       (iVar1 = *(int *)(iVar1 + 0x798), iVar1 != 0)) {
      if (*(char *)(iVar1 + 0x37) == '\x02') {
        iVar1 = FUN_005d0450(param_1,*(undefined4 *)(iVar1 + 0x6c));
        if (iVar1 != 0) goto LAB_004cda04;
      }
      if (*(int *)(*(int *)((&DAT_0093d7f0)[iVar2] + 0x798) + 0x6c) == param_1) {
LAB_004cda04:
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = *(undefined4 *)((&DAT_0093d7f0)[iVar2] + 0xca4);
        }
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = (&DAT_0093d7f0)[iVar2];
        }
        return 1;
      }
    }
    iVar2 = iVar2 + 1;
    if (7 < iVar2) {
      return 0;
    }
  } while( true );
}

