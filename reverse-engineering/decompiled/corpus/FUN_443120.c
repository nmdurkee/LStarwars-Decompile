/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x443120; label: FUN_00443120
 */

float10 FUN_00443120(void)

{
  if ((((DAT_0093d810 == 0) || (*(int *)(DAT_0093d810 + 0xcd0) == 0)) ||
      (*(char *)(DAT_0093d810 + 0x7b5) == ';')) &&
     (((DAT_0093d814 == 0 || (*(int *)(DAT_0093d814 + 0xcd0) == 0)) ||
      (*(char *)(DAT_0093d814 + 0x7b5) == ';')))) {
    return (float10)0;
  }
  return (float10)1;
}

