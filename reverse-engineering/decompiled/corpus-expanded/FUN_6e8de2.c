/* Ghidra pseudocode, not original source.
 * ev_0b5d44e813c4aa355d260cb866ec5aec765804eee128937753d2ed60240642a2
 * Entry: 0x6e8de2; label: FUN_006e8de2
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006e8de2(LPCSTR param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = DeleteFileA(param_1);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
  }
  else {
    DVar2 = 0;
  }
  if (DVar2 != 0) {
    FUN_006ead85(DVar2);
    return 0xffffffff;
  }
  return 0;
}

