/* Ghidra analysis pseudocode, not original source.
 * ev_526838828e273a637259fe0c0b8910ed57fcbb113f7ca97b4fe0b36ecb2b0c42
 * Entry: 0x6f024e; label: FUN_006f024e
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

