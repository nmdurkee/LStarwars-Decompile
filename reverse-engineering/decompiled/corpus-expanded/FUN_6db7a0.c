/* Ghidra pseudocode, not original source.
 * ev_d9eb3013c9fda622502628697ce0d7be845892a91a12bfef10a3ae0a3a8d7789
 * Entry: 0x6db7a0; label: FUN_006db7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006db7a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x404) < 1) {
    *(undefined4 *)(in_ECX + 0x404) = DAT_02976bd0;
  }
  if (*(int *)(in_ECX + 0x408) < 1) {
    *(undefined4 *)(in_ECX + 0x408) = DAT_02976bd4;
  }
  if (*(int *)(in_ECX + 0x40c) < 1) {
    *(undefined4 *)(in_ECX + 0x40c) = *(undefined4 *)(in_ECX + 0x404);
  }
  if (*(int *)(in_ECX + 0x410) < 1) {
    *(undefined4 *)(in_ECX + 0x410) = *(undefined4 *)(in_ECX + 0x408);
  }
  if (*(int *)(in_ECX + 0x41c) < 0) {
    *(undefined4 *)(in_ECX + 0x41c) = DAT_02976bd8;
  }
  if ((*(int *)(in_ECX + 0x420) < 0) || (4 < *(int *)(in_ECX + 0x420))) {
    *(undefined4 *)(in_ECX + 0x420) = 0;
  }
  if ((*(int *)(in_ECX + 0x424) < 0) || (3 < *(int *)(in_ECX + 0x424))) {
    *(undefined4 *)(in_ECX + 0x424) = 3;
  }
  if ((*(int *)(in_ECX + 0x428) < 0) || (10 < *(int *)(in_ECX + 0x428))) {
    *(undefined4 *)(in_ECX + 0x428) = 10;
  }
  if ((*(int *)(in_ECX + 0x42c) < 0) || (10 < *(int *)(in_ECX + 0x42c))) {
    *(undefined4 *)(in_ECX + 0x42c) = 8;
  }
  if ((*(int *)(in_ECX + 0x430) < 0) || (10 < *(int *)(in_ECX + 0x430))) {
    *(undefined4 *)(in_ECX + 0x430) = 8;
  }
  if ((*(int *)(in_ECX + 0x440) < 0) || (2 < *(int *)(in_ECX + 0x440))) {
    *(undefined4 *)(in_ECX + 0x440) = 2;
  }
  if ((*(int *)(in_ECX + 0x444) < 0) || (2 < *(int *)(in_ECX + 0x444))) {
    *(undefined4 *)(in_ECX + 0x444) = 2;
  }
  if ((*(int *)(in_ECX + 0x44c) < 0) || (2 < *(int *)(in_ECX + 0x44c))) {
    *(undefined4 *)(in_ECX + 0x44c) = 2;
  }
  if ((*(int *)(in_ECX + 0x450) < 0) || (2 < *(int *)(in_ECX + 0x450))) {
    *(undefined4 *)(in_ECX + 0x450) = 2;
  }
  if ((*(int *)(in_ECX + 0x45c) < 0) || (3 < *(int *)(in_ECX + 0x45c))) {
    *(undefined4 *)(in_ECX + 0x45c) = 0;
  }
  return;
}

