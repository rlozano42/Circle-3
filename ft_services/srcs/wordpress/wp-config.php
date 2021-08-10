<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'rlozano' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

define('WP_CACHE', false);


/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         ')_iIplau+gIW^%GqhG .}xWx-?g:+TVC66CcbAbw%9.Lwm-Xm?@xl]eI(0[VMdmO');
define('SECURE_AUTH_KEY',  '#:62UM/~LQ@R(+|Lt[?D u2:T*g 9;8EAZBa_DY`s|BQr7cW#24X$b$?|Bam+*|-');
define('LOGGED_IN_KEY',    '2tXI*f}j$-@x0q-g=}rek>A!}^!ucwC,%gThW[>r0}@3b(-y#f5AA/yev|eO4=P[');
define('NONCE_KEY',        'h~Gl[NKdBFts+e),!/0r6-HNCTf&|%-wV?Xm=:>6bb>PG*R&e|U2!,GwX{V(lf!H');
define('AUTH_SALT',        'sSAu3+Zj=+(N$V(+tMkP*uq!d6i+%N~X*L)q^Nl=|Y,F-sBW~8m?7#kX7t-Qf=#+');
define('SECURE_AUTH_SALT', 'KqZ)+gH(ZKa_/I!*=@-d/RyhD0?U-ijMbu-|AV-LsU3g_oSW.WE+W,/-#)3K<2NQ');
define('LOGGED_IN_SALT',   ':4p`z]F&<e{WMi=n7LaalB+r*d&;TgF+eL93|(nz+bl*Y-zzUL77>wO^2W@6p#I=');
define('NONCE_SALT',       'UM0f->5!roE|0fx1q+~[FOhSqqep._NC=BP,+_CoUi0ra%BT5Qa)M* ~^? oR|5!');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';