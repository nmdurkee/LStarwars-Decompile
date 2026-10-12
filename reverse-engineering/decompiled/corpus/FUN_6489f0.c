/* Ghidra analysis pseudocode, not original source.
 * ev_b688fd0177351e281ce3a654852fc29d1d3855db670688278c9fb06d06ddbb68
 * Entry: 0x6489f0; label: FUN_006489f0
 */

void FUN_006489f0(char param_1)

{
  char *pcVar1;
  
  pcVar1 = &DAT_0291f7da;
  do {
    if ((*(int *)(pcVar1 + -0x26) != -1) && (*pcVar1 == param_1)) {
      pcVar1[0xe] = -0x66;
      pcVar1[0xf] = '?';
      pcVar1[0x10] = '\x1c';
      pcVar1[0x11] = 'F';
    }
    pcVar1 = pcVar1 + 0x6c;
  } while ((int)pcVar1 < 0x29208ba);
  *(undefined4 *)(&DAT_02913a2c + param_1 * 4) = 1;
  return;
}

