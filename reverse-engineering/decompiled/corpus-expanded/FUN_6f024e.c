/* Ghidra pseudocode, not original source.
 * ev_167fb1af16662301ac7ec00e42056ea51ba92ee67c43a8d5117ba6e42cb74a01
 * Entry: 0x6f024e; label: FUN_006f024e
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

LPVOID FUN_006f024e(void)

{
  LPVOID lpTlsValue;
  
  lpTlsValue = TlsGetValue(DAT_00829ab8);
  if (lpTlsValue == (LPVOID)0x0) {
    lpTlsValue = (LPVOID)FUN_006f01bc(DAT_0297c53c);
    TlsSetValue(DAT_00829ab8,lpTlsValue);
  }
  return lpTlsValue;
}

