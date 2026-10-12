/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4efdf0; label: FUN_004efdf0
 */

void FUN_004efdf0(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  
  if (param_1 == 0) {
    cVar2 = '\\';
  }
  else {
    cVar2 = *(char *)(param_1 + 0x10);
  }
  if (DAT_0091ee84 == 0) {
    cVar1 = *param_2;
    while (cVar1 != '\0') {
      switch(*param_2) {
      case '/':
      case '\\':
        *param_2 = cVar2;
        break;
      case 'a':
      case 'b':
      case 'c':
      case 'd':
      case 'e':
      case 'f':
      case 'g':
      case 'h':
      case 'i':
      case 'j':
      case 'k':
      case 'l':
      case 'm':
      case 'n':
      case 'o':
      case 'p':
      case 'q':
      case 'r':
      case 's':
      case 't':
      case 'u':
      case 'v':
      case 'w':
      case 'x':
      case 'y':
      case 'z':
        *param_2 = *param_2 + -0x20;
      }
      param_2 = param_2 + 1;
      cVar1 = *param_2;
    }
  }
  else if (*param_2 != '\0') {
    do {
      if ((*param_2 == '\\') || (*param_2 == '/')) {
        *param_2 = cVar2;
      }
      param_2 = param_2 + 1;
    } while (*param_2 != '\0');
    return;
  }
  return;
}

