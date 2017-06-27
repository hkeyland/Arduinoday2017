#!/usr/bin/env bash
. bash_tap_fd.sh

PASSWD=$(get_password)
CMD=$(get_script)
TEST="$(get_test_data)"
PAYLOAD="2\n${PASSWD}"


diff -u <(echo -e ${PAYLOAD} | ${CMD} ${TEST} | grep -C1 doesntexist || kill $$) <(get_user_data "doesntexist")
diff -u <(echo -e ${PAYLOAD} | ${CMD} ${TEST} | grep -C1 onemore || kill $$) <(get_user_data "onemore")
diff -u <(echo -e ${PAYLOAD} | ${CMD} ${TEST} | grep -C1 cömplex || kill $$) <(get_user_data "complex")

# vim: ai sts=4 et sw=4
